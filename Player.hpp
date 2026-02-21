#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "AEntity.hpp"

class Player : public AEntity
{
private:
    int score = 0; // player's current score
    int bulletCooldown; // frames until player can shoot again
    short playerNum = 1; // player number (for multiplayer) //2 for second player

public:
    Player();
    Player(Player const &src);
    Player(int bulletCooldown, short playerNum, char entityChar = '@', string color = "green",
           int x = 1, int y = 1, int speed = 1, int health = 10);
    ~Player();

    void update(float deltaTime) override;
    void render(WINDOW *win) const override;
    void onCollision(AEntity &other) override;

    void increaseScore(int amount);
    void shoot();

    int getScore() const;
    int getBulletCooldown() const;
    short getPlayerNum() const { return playerNum; }
    
    void setScore(int newScore);
    void setBulletCooldown(int cooldown);
    void setPlayerNum(short num) { playerNum = num; }
};

#endif