#include "Bullet.hpp"
#include <vector>

// extern vector<AEntity*> g_bullets;
extern vector<AEntity*> g_playerBullets;
extern vector<AEntity*> g_enemyBullets;

// Bullet::Bullet()
//     : AEntity('*', "yellow", 0, 0, 4, 1)
// {
//     g_bullets.push_back(this);
// }

// copy constructor removed: copying is disabled (use clone() instead)

// Bullet::Bullet(char entityChar = '*', int color = PAIR_DEF, int x = 1, int y = 1, int updateInterval = 8, int health = 1000000000, int scoreValue = 0)
Bullet::Bullet(bool isPlayerBullet, char entityChar, int color, int x, int y, int updateInterval, int health, int scoreValue)
    : AEntity(entityChar, color, x, y, updateInterval, health, scoreValue), 
      isPlayerBullet(isPlayerBullet)
{
    if (isPlayerBullet) {
        g_playerBullets.push_back(this);
    } else {
        g_enemyBullets.push_back(this);
    }
}

Bullet::~Bullet() {}

AEntity* Bullet::clone(int x, int y) const
{
    int nx = (x != -1) ? x : getPosX();
    int ny = (y != -1) ? y : getPosY();
    Bullet *b = new Bullet(isPlayerBullet, getEntityChar(), getColor(), nx, ny, getUpdateInterval(), getHealth(), getScoreValue());
    b->setVel(getVelX(), getVelY());
    if (!getIsAlive()) b->setAlive(false);
    return b;
}

void	Bullet::update(float deltaTime)
{
    (void)deltaTime;
    // move bullet in direction of velocity
    int nx = getPosX() + getVelX();
    int ny = getPosY() + getVelY();
    setPos(nx, ny);
}

void	Bullet::render(WINDOW *win) const
{
    int color = getColor();

	wattron(win, COLOR_PAIR(color));
    mvwaddch(win, getPosY(), getPosX(), getEntityChar());
    wattroff(win, COLOR_PAIR(color));
}

void	Bullet::onCollision(AEntity &other)
{
    (void)other;
}
