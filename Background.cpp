#include "Background.hpp"
#include "AEntity.hpp"
#include <ncurses.h>

extern vector<AEntity*> g_background;

Background::Background()
    : AEntity(ACS_BULLET, PAIR_DEF, 20, 0, 60, 0, 0)
{
    g_background.push_back(this);
}

Background::Background(Background const &src)
    : AEntity(src)
{
    // g_Backgroundoids.push_back(this); copia?
}

Background::Background(char entityChar, int color, int x, int y, int updateInterval, int health, int scoreValue)
    : AEntity(entityChar, color, x, y, updateInterval, health, scoreValue)
{
    g_background.push_back(this);
}

Background::~Background() {}

void	Background::update(float deltaTime)
{
    (void)deltaTime;
    // move Background in direction of velocity
    int nx = getPosX() + getVelX();
    int ny = getPosY() + getVelY();
    setPos(nx, ny);
}

AEntity* Background::clone(int x, int y) const
{
    int nx = (x != -1) ? x : getPosX();
    int ny = (y != -1) ? y : getPosY();
    Background *a = new Background(getEntityChar(), getColor(), nx, ny, getUpdateInterval(), getHealth(), getScoreValue());
    a->setVel(getVelX(), getVelY());
    if (!getIsAlive()) a->setAlive(false);
    return a;
}

void	Background::render(WINDOW *win) const
{
    int color = getColor();

	wattron(win, COLOR_PAIR(color));
	mvwaddch(win, getPosY(), getPosX(), getEntityChar());
	wattroff(win, COLOR_PAIR(color));
}

void	Background::onCollision(AEntity &other)
{
    (void)other;
}