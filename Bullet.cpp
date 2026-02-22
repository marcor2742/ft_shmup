#include "Bullet.hpp"
#include <vector>

extern vector<AEntity*> g_bullets;

// Bullet::Bullet()
//     : AEntity('*', "yellow", 0, 0, 4, 1)
// {
//     g_bullets.push_back(this);
// }

Bullet::Bullet(Bullet const &src)
    : AEntity(src)
{
    // g_bullets.push_back(this); copia?
}

Bullet::Bullet(char entityChar, string color, int x, int y, int updateInterval, int health, int scoreValue)
    : AEntity(entityChar, color, x, y, updateInterval, health, scoreValue)
{
    g_bullets.push_back(this);
}

Bullet::~Bullet() {}

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
    mvwaddch(win, getPosY(), getPosX(), getEntityChar());
}

void	Bullet::onCollision(AEntity &other)
{
    (void)other;
}
