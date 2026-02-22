#ifndef ASTEROID_HPP
#define ASTEROID_HPP

#include "AEntity.hpp"

class Aster : public AEntity
{
private:
	int	my_color;

public:
    Aster();
	Aster(Aster const &src);
	Aster(char entityChar = 'O', int color = PAIR_GREY, int x = 1, int y = 1, int updateInterval = 12, int health = 1000000000, int scoreValue = 0);
    ~Aster();

	void	update(float deltaTime);
	void	render(WINDOW *win) const;
	void	onCollision(AEntity &other);
};
	
#endif