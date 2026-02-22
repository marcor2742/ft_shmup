#ifndef AENTITY_HPP
#define AENTITY_HPP

#include <iostream>
#include <string>
#include <ncurses.h>
#include "colours.h"
#include <vector>

//init_color
enum
{
	GREY = 10,
	BR_YELLOW,
	BR_GREEN,
	L_PINK,
	L_RED,
	SKY_BLUE,
	BR_PINK,
	ORANGE,
	DR_GRAY
};

//init_pair
enum
{
	PAIR_GREY = 10,
	PAIR_BR_YELLOW,
	PAIR_BR_GREEN,
	PAIR_L_PINK,
	PAIR_L_RED,
	PAIR_ORANGE,
	PAIR_BR_PINK,
	PAIR_SKY_BLUE,
	PAIR_RED,
	PAIR_GREEN,
	PAIR_YELLOW,
	PAIR_BLUE,
	PAIR_MAGENTA,
	PAIR_CYAN,
	PAIR_DEF,
	PAIR_DR_GRAY
};

using namespace std;

class AEntity
{
protected:
	char	entityChar;	// character displayed on screen
	int		color;

	int	start_x, start_y;	// spawn position
	int	pos_x, pos_y;		// current position
	int	vel_x, vel_y;		// velocity vector (direction)
	int	updateInterval;		// update every N frames

	int	health;		// current HP
	int	maxHealth;	// max HP (useful for bosses / health bars)
	bool	isAlive;

	int	scoreValue;	// points awarded to player on kill

public:
	AEntity();
	AEntity(AEntity const &aentity);
	AEntity(char entityChar, int color,
		int x, int y, int updateInterval, int health, int scoreValue = 0);
	virtual ~AEntity();

	// --- Pure virtual: every entity must implement these ---
	virtual void		update(float deltaTime) = 0;
	virtual void		render(WINDOW *win) const = 0;
	virtual void		onCollision(AEntity &other) = 0;
	// clone: crea copia heap+registrata; x/y=-1 mantiene la posizione originale
	virtual AEntity*	clone(int x = -1, int y = -1) const = 0;

	// --- Virtual with shared default behaviour ---
	virtual void	takeDamage(int dmg);
	virtual void	kill();

	// --- Getters ---
	int		getPosX() const;
	int		getPosY() const;
	int		getVelX() const;
	int		getVelY() const;
	int		getUpdateInterval() const;
	int		getHealth() const;
	int		getMaxHealth() const;
	int		getScoreValue() const;
	bool	getIsAlive() const;
	char	getEntityChar() const;
	int		getColor() const;

	// --- Setters ---
	void	setPos(int x, int y);
	void	setVel(int vx, int vy);
	void	setHealth(int h);
	void	setAlive(bool alive);
	void	setUpdateInterval(int n);
};

void	init_colors(void);

#endif