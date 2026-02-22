#include "Asteroid.hpp"

extern vector<AEntity*> g_asteroids;

Aster::Aster()
    : AEntity('Q', PAIR_GREY, 20, 4, 60, 0, 0)
{
    g_asteroids.push_back(this);
}

Aster::Aster(Aster const &src)
    : AEntity(src)
{
    // g_asteroids.push_back(this); copia?
}

Aster::Aster(char entityChar, int color, int x, int y, int updateInterval, int health, int scoreValue)
    : AEntity(entityChar, color, x, y, updateInterval, health, scoreValue)
{
    g_asteroids.push_back(this);
}

Aster::~Aster() {}

void	Aster::update(float deltaTime)
{
    (void)deltaTime;
    // move Aster in direction of velocity
    int nx = getPosX() + getVelX();
    int ny = getPosY() + getVelY();
    setPos(nx, ny);
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