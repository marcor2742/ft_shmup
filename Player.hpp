#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "AEntity.hpp"

class Player : public AEntity
{
private:
    int score = 0;
    short playerNum = 1; // player number (for multiplayer) //2 for second player
    string  ship_type = " A \n/|\\";

public:
    Player();
    Player(short playerNum, char entityChar = '@', int color = PAIR_BR_GREEN,
           int x = 1, int y = 1, int updateInterval = 8, int health = 10);
    ~Player();

void		update(float deltaTime) override;
	void		render(WINDOW *win) const override;
	void		onCollision(AEntity &other) override;
	AEntity*	clone(int x = -1, int y = -1) const override; // lancia sempre: i Player non si clonano

    void increaseScore(int amount);
    void shoot();

    int getScore() const;
    short getPlayerNum() const { return playerNum; }
    string getString() const;

    void setScore(int newScore);
    void setPlayerNum(short num) { playerNum = num; }
};

#endif