#include "AEntity.hpp"

// --- Constructors / Destructor ---

AEntity::AEntity()
	: entityChar('?'), color(PAIR_DEF),
	  start_x(0), start_y(0),
	  pos_x(0), pos_y(0),
	  vel_x(0), vel_y(0),
	  updateInterval(1), health(1), maxHealth(1),
	  isAlive(true), scoreValue(0)
{}

AEntity::AEntity(AEntity const &src)
	: entityChar(src.entityChar), color(src.color),
	  start_x(src.start_x), start_y(src.start_y),
	  pos_x(src.pos_x), pos_y(src.pos_y),
	  vel_x(src.vel_x), vel_y(src.vel_y),
	  updateInterval(src.updateInterval), health(src.health), maxHealth(src.maxHealth),
	  isAlive(src.isAlive), scoreValue(src.scoreValue)
{}

AEntity::AEntity(char entityChar, int color,
				 int x, int y, int updateInterval, int health, int scoreValue)
	: entityChar(entityChar), color(color),
	  start_x(x), start_y(y),
	  pos_x(x), pos_y(y),
	  vel_x(0), vel_y(0),
	  updateInterval(updateInterval), health(health), maxHealth(health),
	  isAlive(true), scoreValue(scoreValue)
{}

AEntity::~AEntity() {}

// --- Virtual behaviour ---

void	AEntity::takeDamage(int dmg)
{
	health -= dmg;
	if (health <= 0)
		kill();
}

void	AEntity::kill()
{
	health = 0;
	isAlive = false;
}

// --- Getters ---

int		AEntity::getPosX()		const { return pos_x; }
int		AEntity::getPosY()		const { return pos_y; }
int		AEntity::getVelX()		const { return vel_x; }
int		AEntity::getVelY()		const { return vel_y; }
int		AEntity::getUpdateInterval()	const { return updateInterval; }
int		AEntity::getHealth()	const { return health; }
int		AEntity::getMaxHealth()	const { return maxHealth; }
int		AEntity::getScoreValue()	const { return scoreValue; }
bool	AEntity::getIsAlive()	const { return isAlive; }

char	AEntity::getEntityChar()	const { return entityChar; }
int		AEntity::getColor()		const { return color; }

// --- Setters ---

void	AEntity::setPos(int x, int y)		{ pos_x = x; pos_y = y; }
void	AEntity::setVel(int vx, int vy)		{ vel_x = vx; vel_y = vy; }
void	AEntity::setHealth(int h)			{ health = (h > maxHealth ? maxHealth : h); }
void	AEntity::setAlive(bool alive)		{ isAlive = alive; }
void	AEntity::setUpdateInterval(int n)	{ updateInterval = n; }