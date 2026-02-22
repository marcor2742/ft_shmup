#ifndef BULLET_HPP
#define BULLET_HPP

#include "AEntity.hpp"

class Bullet : public AEntity
{
private:


public:
    // Bullet();
	Bullet(Bullet const &src);
	Bullet(char entityChar = '*', string color = "grey", int x = 1, int y = 1, int updateInterval = 8, int health = 1000000000, int scoreValue = 0);
    ~Bullet();

	void	update(float deltaTime);
	void	render(WINDOW *win) const;
	void	onCollision(AEntity &other);
};
	
#endif