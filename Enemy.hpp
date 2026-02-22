#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "AEntity.hpp"

class Enemy : public AEntity {
public:
	// Enemy(); viene usato il costruttore con parametri messi a default
    Enemy(char entityChar = 'W', int color = PAIR_L_PINK, int x = 1, int y = 1, int updateInterval = 12, int health = 5, int scoreValue = 10);
    ~Enemy();

	void		update(float deltaTime) override;
	void		render(WINDOW *win) const override;
	void		onCollision(AEntity &other) override;
	AEntity*	clone(int x = -1, int y = -1) const override;
	void		shoot();
};

#endif