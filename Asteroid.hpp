#ifndef ASTEROID_HPP
#define ASTEROID_HPP

#include "AEntity.hpp"

class Aster : public AEntity
{
private:

public:
	Aster();
	Aster(char entityChar = 'Q', int color = PAIR_GREY, int x = 1, int y = 1, int updateInterval = 12, int health = 1000000000, int scoreValue = 0);
    ~Aster();

	void		update(float deltaTime) override;
	void		render(WINDOW *win) const override;
	void		onCollision(AEntity &other) override;
	AEntity*		clone(int x = -1, int y = -1) const override;
};
	
#endif