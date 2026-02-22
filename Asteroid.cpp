#include "Asteroid.hpp"

extern vector<AEntity*> g_asteroids;

Aster::Aster()
    : AEntity('Q', "grey", 20, 4, 60, 0, 0)
{
    g_asteroids.push_back(this);
}

Aster::Aster(Aster const &src)
    : AEntity(src)
{
    // g_asteroids.push_back(this); copia?
}

Aster::Aster(char entityChar, string color, int x, int y, int updateInterval, int health, int scoreValue)
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
    if (has_colors() != FALSE)
	{
        start_color();
        use_default_colors();
		init_color(GREY, 600, 800, 1000);
        init_pair(PAIR_GREY, GREY, COLOR_RED);

        wattron(win, COLOR_PAIR(PAIR_GREY));
        mvwaddch(win, getPosY(), getPosX(), getEntityChar());
        wattroff(win, COLOR_PAIR(PAIR_GREY));
	}
}

void	Aster::onCollision(AEntity &other)
{
    (void)other;
}