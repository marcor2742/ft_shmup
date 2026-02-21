#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "AEntity.hpp"

class Player : public AEntity
{
private:
    int score = 0;
    short playerNum = 1; // player number (for multiplayer) //2 for second player

public:
    Player();
    Player(Player const &src);
    Player(short playerNum, char entityChar = '@', string color = "green",
           int x = 1, int y = 1, int updateInterval = 8, int health = 10);
    ~Player();

    void update(float deltaTime) override;
    void render(WINDOW *win) const override;
    void onCollision(AEntity &other) override;

    void increaseScore(int amount);
    void shoot();

    int getScore() const;
    short getPlayerNum() const { return playerNum; }

    void setScore(int newScore);
    void setPlayerNum(short num) { playerNum = num; }
};

#endif