#ifndef ASTEROID_HPP
#define ASTEROID_HPP

#include "AEntity.hpp"

class Aster : public AEntity
{
private:


public:
    Aster();
    ~Aster();

	void	update(float deltaTime);
	void	render(WINDOW *win) const;
	void	onCollision(AEntity &other);
};
	
#endif