#include "Player.hpp"
#include <iostream>

Player::Player()
    : AEntity('@', "green", 1, 1, 1, 10), score(0), bulletCooldown(0)
{}

Player::Player(Player const &src)
    : AEntity(src), score(src.score), bulletCooldown(src.bulletCooldown)
{}

Player::Player(int bulletCooldown, char entityChar, string color,
           int x, int y, int speed, int health)
    : AEntity(entityChar, color, x, y, speed, health), score(0), bulletCooldown(bulletCooldown)
{}

Player::~Player() {}

void Player::update(float deltaTime) override
{
    // Handle player input and movement here
}

void Player::shoot()
{
    if (bulletCooldown <= 0) {
        // Create a new bullet entity and set its velocity
        // Reset bullet cooldown
        bulletCooldown = 20; // Example cooldown duration
    }
}

void Player::render(WINDOW *win) const override
{
    // imposta colori e funzione per spostare char in posizione
}

void Player::onCollision(AEntity &other) override 
{
    // Handle collision with other entities (e.g., enemies, power-ups)
}

void Player::increaseScore(int amount) { score += amount; }

int Player::getScore() const { return score; }
int Player::getBulletCooldown() const { return bulletCooldown; }

void Player::setScore(int newScore) { score = newScore; }
void Player::setBulletCooldown(int cooldown) { bulletCooldown = cooldown; }