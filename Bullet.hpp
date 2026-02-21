#ifndef BULLET_HPP
#define BULLET_HPP

#include "AEntity.hpp"

class Bullet : public AEntity
{
private:


public:
    Bullet();
    ~Bullet();

	void	update(float deltaTime);
	void	render(WINDOW *win) const;
	void	onCollision(AEntity &other);
};
	
#endif