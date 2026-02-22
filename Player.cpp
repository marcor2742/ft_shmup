#include "Player.hpp"
#include "Bullet.hpp"
#include <stdexcept>

extern bool g_running;
extern vector<AEntity*> g_players;

Player::Player()
    : AEntity('@', PAIR_BR_GREEN, 1, 1, 8, 10), score(0), playerNum(1)
{
    if (playerNum < 1 || playerNum > 2)
        throw std::runtime_error("Invalid player number (must be 1 or 2)");

    for (AEntity *e : g_players) {
        Player *p = dynamic_cast<Player*>(e);
        if (p && p->getPlayerNum() == playerNum)
            throw std::runtime_error("Player with same playerNum already exists");
    }

    g_players.push_back(this);
}

// copy constructor removed: copying is disabled (use clone() where appropriate)

Player::Player(short playerNum, char entityChar, int color,
           int x, int y, int updateInterval, int health)
    : AEntity(entityChar, color, x, y, updateInterval, health), score(0), playerNum(playerNum)
{
    if (playerNum < 1 || playerNum > 2)
        throw std::runtime_error("Invalid player number (must be 1 or 2)");

    for (AEntity *e : g_players) {
        Player *p = dynamic_cast<Player*>(e);
        if (p && p->getPlayerNum() == playerNum)
            throw std::runtime_error("Player with same playerNum already exists");
    }

    g_players.push_back(this);
}

Player::~Player() {}

AEntity* Player::clone(int x, int y) const
{
    (void)x; (void)y;
    throw std::runtime_error("Cannot clone a Player: each player must have a unique playerNum");
}

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
    // Create a new bullet entity (to be added to the entity list by the game loop)
    // Bullet updateInterval = 4 (updates every 4 frames ~= 16 times/sec at 60fps)
}

void	Player::render(WINDOW *win) const
{
    int color = getColor();

	wattron(win, COLOR_PAIR(color));
	mvwaddch(win, getPosY(), getPosX(), getEntityChar());
	wattroff(win, COLOR_PAIR(color));
}

void Player::onCollision(AEntity &other) 
{
    (void)other;
}

void Player::increaseScore(int amount) { score += amount; }

int Player::getScore() const { return score; }

void Player::setScore(int newScore) { score = newScore; }