#include "Bullet.hpp"

Bullet::Bullet()
    : AEntity('*', "yellow", 0, 0, 4, 1)
{}

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
