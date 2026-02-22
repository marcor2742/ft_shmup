#include "Asteroid.hpp"


extern vector<AEntity*> g_asteroids;

Aster::Aster()
    : AEntity('O', PAIR_GREY, 20, 4, 60, 0, 0)
{
    g_asteroids.push_back(this);
}

// copy constructor removed: copying is disabled (use clone() instead)

Aster::Aster(char entityChar, int color, int x, int y, int updateInterval, int health, int scoreValue)
    : AEntity(entityChar, color, x, y, updateInterval, health, scoreValue)
{
    g_asteroids.push_back(this);
}

Aster::~Aster() {}

AEntity* Aster::clone(int x, int y) const
{
    int nx = (x != -1) ? x : getPosX();
    int ny = (y != -1) ? y : getPosY();
    Aster *a = new Aster(getEntityChar(), getColor(), nx, ny, getUpdateInterval(), getHealth(), getScoreValue());
    a->setVel(getVelX(), getVelY());
    if (!getIsAlive()) a->setAlive(false);
    return a;
}

void	Aster::update(float deltaTime)
{
    (void)deltaTime;
    // move Aster in direction of velocity
    int nx = getPosX() + getVelX();
    int ny = getPosY() + getVelY();
    setPos(nx, ny);
    if (getPosY() > 50) { // if enemy goes off screen, kill it
		kill();
	}
}

void	Aster::render(WINDOW *win) const
{
    int color = getColor();

	wattron(win, COLOR_PAIR(color));
	mvwaddch(win, getPosY(), getPosX(), getEntityChar());
	wattroff(win, COLOR_PAIR(color));
}

void	Aster::onCollision(AEntity &other)
{
    (void)other;
}