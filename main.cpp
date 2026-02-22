#include <iostream>
#include <ncurses.h>
#include <chrono>
#include <unistd.h>
#include "Player.hpp"
#include "Bullet.hpp"
#include "Background.hpp"
#include "Asteroid.hpp"
#include "Enemy.hpp"
#include "AEntity.hpp"
#include <vector>
using namespace std;
using game_clock = std::chrono::steady_clock;

// target: 60 frames per second
static const int   FPS        = 60;
static const long  FRAME_US   = 1000000 / FPS; // microseconds per frame (~16666 us)

// vector<AEntity*> g_entities;
bool g_running = false;

vector<AEntity*> g_asteroids;
vector<AEntity*> g_enemies;
vector<AEntity*> g_players;
vector<AEntity*> g_bullets;
vector<AEntity*> g_background;

// defined in ncurses
// COLOR_BLACK   0
// COLOR_RED     1
// COLOR_GREEN   2
// COLOR_YELLOW  3
// COLOR_BLUE    4
// COLOR_MAGENTA 5
// COLOR_CYAN    6
// COLOR_WHITE   7

//keyboard input
// KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
//wasd: w=119, a=97, s=115, d=100
// shoot (space and keypad 0): 32 and 48

// gestione del punteggio
// gestione del game over
// cancellazzione dei nemici se escono dallo schermo
// enemy con movimenti più complessi. metere un numero massimo e che possono anche alire.
// controlla multiplayer, frecce direzionali non funzionano

void updateEntities(vector<AEntity*> &entities, int frame);
void deleteEntity(vector<AEntity*> &entities);
void renderEntities(vector<AEntity*> &entities, WINDOW *win);
void handleCollisions(Player &player);
void free_all_entities();
void createRandomEntity(int h_game, int w_game);
void createBackground(int h_game, int w_game);

int main() {
    initscr();

    noecho(); //don't print input characters
    nodelay(stdscr, TRUE); // make getch non-blocking
    keypad(stdscr, TRUE); // enable arrow keys
    curs_set(0); // hide cursor
    init_colors();
    
    int h, w;
    getmaxyx(stdscr, h, w);
	(void)h; 
    
    int w_game = 40;
    int h_game = 40;
    // int w_score = 20;    

    WINDOW *winGame = newwin(h_game, w_game, 0, 0);
    wbkgd(winGame, COLOR_PAIR(PAIR_DEF)); //per fare tutto lo sfondo di questo colore
    box(winGame, 0, 0);
    wrefresh(winGame);
    
    WINDOW *winScore = newwin(h_game, w-w_game, 0, w_game);
    box(winScore, 0, 0);
    wrefresh(winScore);
    
    
    
    int frame = 0;
    g_running = true;
    Player *player= new Player(1, '@', PAIR_GREEN, 2, 2, 8, 10); // playerNum=1, spawn at (2,2)
    // Player *player2= new Player(2, '@', PAIR_GREEN, 4, 4, 8, 10); 
    // (void)player2;
    // g_entities.push_back(player);
    // Aster *aster = new Aster('O', PAIR_GREEN, 20, 0, 60); // AsterNum=1, spawn at (2,2)
    // aster->setVel(0, 1);
    // g_entities.push_back(aster);
    // Enemy *enemy = new Enemy('W', PAIR_MAGENTA, 10, 0, 24, 5, 10);
    // (void)enemy;
    // g_entities.push_back(enemy);

    // Background *star = new Background('.', PAIR_GREY, 30, 0, 60); // BackgroundNum=1, spawn at (2,2)
    // star->setVel(0, 1);

    // AEntity *enemy2 = enemy->clone(11, -1); // clone enemy at different position
	// (void)enemy2;

    createBackground(h_game, w_game);
    renderEntities(g_background, winGame);
    wrefresh(winGame);

    vector<vector<AEntity*>*> groups = {
        &g_players, &g_enemies, &g_bullets, &g_asteroids, &g_background
    };
    while (g_running) {
        auto frameStart = game_clock::now();

        createRandomEntity(h_game, w_game); // probabilità di spawnare un nemico ogni frame

        // size_t size = g_entities.size();
        // for (size_t i = 0; i < size; i++) {
        //     AEntity *e = g_entities[i];
        //     if (frame % e->getUpdateInterval() == 0)
        //         e->update(0.0f);
        // }
		//updateEntities(g_entities, frame);
		for (auto group : groups) {	
			if (!group) continue;
			updateEntities(*group, frame);
		}

        // for (auto it = g_entities.begin(); it != g_entities.end(); ) {
        //     if (!(*it)->getIsAlive()) {
        //         delete *it;
        //         it = g_entities.erase(it);
        //     } else {
        //         ++it;
        //     }
        // }
		//deleteEntity(g_entities);
		for (auto group : groups) {
			if (!group) continue;
			deleteEntity(*group);
		}
        handleCollisions(*player);

        // --- render ---
        werase(winGame);
        werase(winScore);

        // player->render(winGame);
        // for (AEntity *e : g_entities) {
        //     e->render(winGame);
        // }
        for (auto group : groups) {
            if (!group) continue;
            renderEntities(*group, winGame);
        }
        renderEntities(g_players, winGame); // render player in front of everything else

        box(winGame, 0, 0);
        mvwprintw(winGame,  1, 2, "frame %d", frame);
        mvwprintw(winScore, 1, 2, "score: %d", player->getScore());
		mvwprintw(winScore, 2, 2, "health: %d/%d", player->getHealth(), player->getMaxHealth());
        wrefresh(winGame);
        wrefresh(winScore);

        // --- sleep for remainder of frame ---
        auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(
            game_clock::now() - frameStart).count();
        if (elapsed < FRAME_US)
            usleep((useconds_t)(FRAME_US - elapsed));

        ++frame;
    }
    free_all_entities();

    delwin(winGame);
    delwin(winScore);
    curs_set(1);
    endwin();
}

void createBackground(int h_game, int w_game)
{
    for (int i = 0; i < w_game * 2; i++) {
        // int r = rand() % 100;
    
        int x = rand() % (w_game - 2) + 1; // spawn within horizontal bounds
        int y = rand() % (h_game - 2) + 1; // spawn within vertical bounds
        Background *s = new Background('.', PAIR_DR_GRAY, x, y, 60);
        s->setVel(0, 1);
    }
}

void createRandomEntity(int h_game, int w_game) {
    (void)h_game; 
    int r = rand() % 100;
    if (r < 3) { // 5% chance to spawn an enemy
        int x = rand() % (w_game - 2) + 1; // spawn within horizontal bounds
        new Enemy('W', PAIR_MAGENTA, x, 0, 24, 1, 10);
    }
    if (r < 1) { // 2% chance to spawn an asteroid
        int x = rand() % (w_game - 2) + 1; // spawn within horizontal bounds
        Aster *a = new Aster('O', PAIR_GREY, x, 0, 60);
        a->setVel(0, 1); // move downwards
    }
    if (r < 5) { // 5% chance to spawn a star
        int x = rand() % (w_game - 2) + 1; // spawn within horizontal bounds
        Background *s = new Background('.', PAIR_DR_GRAY, x, 0, 60);
        s->setVel(0, 1); // move downwards
    }
}


void updateEntities(vector<AEntity*> &entities, int frame) {
	int size = entities.size();
    for (int i = 0; i < size; i++) {
        AEntity *e = entities[i];
        if (frame % e->getUpdateInterval() == 0)
            e->update(0.0f);
    }
}

void deleteEntity(vector<AEntity*> &entities) {
    for (auto it = entities.begin(); it != entities.end(); ) {
        if (!(*it)->getIsAlive()) {
            delete *it;
            it = entities.erase(it);
        } else {
            ++it;
        }
    }
}

void renderEntities(vector<AEntity*> &entities, WINDOW *win) {
    for (AEntity *e : entities) {
        e->render(win);
    }
}

void handleCollisions(Player &player) {
    // proiettili player vs nemici
    for (auto *b : g_bullets)
        for (auto *e : g_enemies)
            if (b->getPosX() == e->getPosX() && b->getPosY() == e->getPosY()) 
			{
                e->takeDamage(1);
                b->setAlive(false); // kill bullet on hit
                if (!e->getIsAlive()) {
                    player.increaseScore(e->getScoreValue());
                }
            }

    // proiettili nemici vs player
    for (auto *b : g_bullets)
        for (auto *p : g_players)
            if (b->getPosX() == p->getPosX() && b->getPosY() == p->getPosY())
			{
                p->takeDamage(1);
                b->setAlive(false); // kill bullet on hit
                if (!p->getIsAlive()) {
                    // game over
                    g_running = false;
                    free_all_entities();

                }
            }

    // asteroidi vs player
    for (auto *a : g_asteroids)
        for (auto *p : g_players)
            if (a->getPosX() == p->getPosX() && a->getPosY() == p->getPosY())
			{
                p->takeDamage(1);
                a->setAlive(false); // destroy asteroid on collision
                if (!p->getIsAlive()) {
                    // game over
                    g_running = false;
                    free_all_entities();
                }
            }
}

void free_all_entities() {
    for (auto group : {&g_players, &g_enemies, &g_bullets, &g_asteroids}) {
        if (!group) continue;
        for (AEntity *e : *group)
            delete e;
        group->clear();
    }
}