#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "AEntity.hpp"

class Player : public AEntity
{
private:
    int score = 0; // player's current score
    int bulletCooldown; // frames until player can shoot again

public:
    Player();
    Player(Player const &src);
    Player(int bulletCooldown, char entityChar = '@', string color = "green",
           int x = 1, int y = 1, int speed = 1, int health = 10);
    ~Player();

    void update(float deltaTime) override;
    void render(WINDOW *win) const override;
    void onCollision(AEntity &other) override;

    void increaseScore(int amount);
    void shoot();

    int getScore() const;
    int getBulletCooldown() const;
    
    void setScore(int newScore);
    void setBulletCooldown(int cooldown);
};

#endif