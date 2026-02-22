#include "Enemy.hpp"
#include "Bullet.hpp"
#include <vector>

extern vector<AEntity*> g_enemies;

// copy constructor removed: copying is disabled (use clone() instead)

Enemy::Enemy(char entityChar, int color, int x, int y, int updateInterval, int health, int scoreValue)
	: AEntity(entityChar, color, x, y, updateInterval, health, scoreValue)
{
	g_enemies.push_back(this);
}

Enemy::~Enemy() {}

AEntity* Enemy::clone(int x, int y) const
{
	int nx = (x != -1) ? x : getPosX();
	int ny = (y != -1) ? y : getPosY();
	Enemy *e = new Enemy(getEntityChar(), getColor(), nx, ny, getUpdateInterval(), getHealth(), getScoreValue());
	e->setVel(getVelX(), getVelY());
	if (!getIsAlive()) e->setAlive(false);

	return e;
}

void	Enemy::update(float deltaTime)
{
	(void)deltaTime;
	// simple AI: move down every update
	int nx = getPosX();
	int ny = getPosY() + 1;
	setPos(nx, ny);
	// shoot randomly
	if (rand() % 20 == 0) {
		shoot();
	}
}

void	Enemy::render(WINDOW *win) const
{
	mvwaddch(win, getPosY(), getPosX(), getEntityChar());
}

void	Enemy::onCollision(AEntity &other)
{
	(void)other;
}

void	Enemy::shoot()
{
	Bullet *b = new Bullet();
    b->setPos(getPosX(), getPosY() + 1);
    b->setVel(0, +1); // shoot upwards
}