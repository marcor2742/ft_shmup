#ifndef Background_HPP
# define Background_HPP

# include "AEntity.hpp"
 
class Background : public AEntity
{
private:

public:
    Background();
	Background(Background const &src);
	Background(char entityChar = 'Q', int color = PAIR_GREY, int x = 1, int y = 1, int updateInterval = 12, int health = 1000000000, int scoreValue = 0);
    ~Background();

	void	update(float deltaTime) override;
	void	render(WINDOW *win) const override;
	void	onCollision(AEntity &other) override;

	AEntity*	clone(int x = -1, int y = -1) const override;
};
	
#endif