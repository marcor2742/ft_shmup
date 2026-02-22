#ifndef Background_HPP
# define Background_HPP

# include "AEntity.hpp"
 
class Background : public AEntity
{
private:
	int	my_color;

public:
    Background();
	Background(Background const &src);
	Background(char entityChar = 'Q', int color = PAIR_GREY, int x = 1, int y = 1, int updateInterval = 12, int health = 1000000000, int scoreValue = 0);
    ~Background();

	void	update(float deltaTime);
	void	render(WINDOW *win) const;
	void	onCollision(AEntity &other);
};
	
#endif