#include "Enemy.hpp"
#include "Bullet.hpp"
#include <vector>

extern vector<AEntity*> g_enemies;

Enemy::Enemy(Enemy const &src)
	: AEntity(src)
{
	// g_enemies.push_back(this); copia?
}

Enemy::Enemy(char entityChar, string color, int x, int y, int updateInterval, int health, int scoreValue)
	: AEntity(entityChar, color, x, y, updateInterval, health, scoreValue)
{
	g_enemies.push_back(this);
}

Enemy::~Enemy() {}

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