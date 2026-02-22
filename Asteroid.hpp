#ifndef ASTEROID_HPP
#define ASTEROID_HPP

#include "AEntity.hpp"

class Aster : public AEntity
{
private:


public:
    Aster();
	Aster(Aster const &src);
	Aster(char entityChar = 'Q', string color = "grey", int x = 1, int y = 1, int updateInterval = 12, int health = 1000000000, int scoreValue = 0);
    ~Aster();

	void	update(float deltaTime);
	void	render(WINDOW *win) const;
	void	onCollision(AEntity &other);
};
	
#endif