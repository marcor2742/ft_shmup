#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "AEntity.hpp"

class Enemy : public AEntity {
public:
	// Enemy(); viene usato il costruttore con parametri messi a default
	Enemy(Enemy const &src);
    Enemy(char entityChar = 'W', int color = PAIR_L_PINK, int x = 1, int y = 1, int updateInterval = 12, int health = 5, int scoreValue = 10);
    ~Enemy();

	void	update(float deltaTime);
	void	render(WINDOW *win) const;
	void	onCollision(AEntity &other);
	void	shoot();
};

#endif