#include "Player.hpp"
#include "Bullet.hpp"
#include <iostream>
#include <vector>

extern vector<AEntity*> g_entities;
extern bool g_running;

Player::Player()
    : AEntity('@', "green", 1, 1, 8, 10), score(0), playerNum(1)
{}

Player::Player(Player const &src)
    : AEntity(src), score(src.score), playerNum(src.playerNum)
{}

Player::Player(short playerNum, char entityChar, string color,
           int x, int y, int updateInterval, int health)
    : AEntity(entityChar, color, x, y, updateInterval, health), score(0), playerNum(playerNum)
{}

Player::~Player() {}

void Player::update(float deltaTime)
{
    (void)deltaTime;

    int vx = 0, vy = 0;
    int ch;
    while ((ch = getch()) != ERR) {
        if (ch == 'q') { g_running = false; return; }
        if (playerNum == 1) {
            if (ch == 'a')           vx = -1;
            else if (ch == 'd')      vx =  1;
            else if (ch == 'w')      vy = -1;
            else if (ch == 's')      vy =  1;
            else if (ch == ' ')      shoot();
        } else if (playerNum == 2) {
            if (ch == KEY_LEFT)      vx = -1;
            else if (ch == KEY_RIGHT) vx =  1;
            else if (ch == KEY_UP)   vy = -1;
            else if (ch == KEY_DOWN) vy =  1;
            else if (ch == '0')      shoot();
        }
    }
    setVel(vx, vy);

    // move and clamp inside game area (border = 1 cell)
    int nx = getPosX() + vx;
    int ny = getPosY() + vy;
    if (nx < 1)  nx = 1;
    if (ny < 1)  ny = 1;
    if (nx > 38) nx = 38;  // w_game - 2
    if (ny > 38) ny = 38;  // h_game - 2
    setPos(nx, ny);
}

void Player::shoot()
{
    Bullet *b = new Bullet();
    b->setPos(getPosX(), getPosY() - 1);
    b->setVel(0, -1); // shoot upwards
    g_entities.push_back(b); // add bullet to global entity list (to be updated and rendered by game loop)
    // Create a new bullet entity (to be added to the entity list by the game loop)
    // Bullet updateInterval = 4 (updates every 4 frames ~= 16 times/sec at 60fps)
}

void Player::render(WINDOW *win) const
{
    if (has_colors() != FALSE)
	{
        start_color();
        use_default_colors();   // permette di usare -1 come colore di default

        init_pair(1, COLOR_MAGENTA, -1);

        wattron(win, COLOR_PAIR(1));
        mvwaddch(win, getPosY(), getPosX(), getEntityChar());
        wattroff(win, COLOR_PAIR(1));
	}
    // Handle collision with other entities (e.g., enemies, power-ups)
}

void Player::onCollision(AEntity &other) 
{
    (void)other;
}

void Player::increaseScore(int amount) { score += amount; }

int Player::getScore() const { return score; }

void Player::setScore(int newScore) { score = newScore; }