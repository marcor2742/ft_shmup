#ifndef BULLET_HPP
#define BULLET_HPP

#include "AEntity.hpp"

class Bullet : public AEntity
{
private:
	bool isPlayerBullet; // true if bullet is shot by player, false if shot by enemy

public:
	// Bullet(); ora il default e' il costruttore con i parametri (avendo un default per ogni parametro)
	Bullet(bool isPlayerBullet = true, char entityChar = '*', int color = PAIR_DEF, int x = 1, int y = 1, int updateInterval = 8, int health = 1000000000, int scoreValue = 0);
    ~Bullet();

	void		update(float deltaTime) override;
	void		render(WINDOW *win) const override;
	void		onCollision(AEntity &other) override;
	AEntity*	clone(int x = -1, int y = -1) const override;
};
	
#endif