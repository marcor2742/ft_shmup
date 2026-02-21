#include "Player.hpp"
#include <iostream>

Player::Player()
    : AEntity('@', "green", 1, 1, 1, 10), score(0), bulletCooldown(0), playerNum(1)
{}

Player::Player(Player const &src)
    : AEntity(src), score(src.score), bulletCooldown(src.bulletCooldown), playerNum(src.playerNum)
{}

Player::Player(int bulletCooldown, short playerNum, char entityChar, string color,
           int x, int y, int speed, int health)
    : AEntity(entityChar, color, x, y, speed, health), score(0), bulletCooldown(bulletCooldown), playerNum(playerNum)
{}

Player::~Player() {}

void Player::update(float deltaTime) override
{
    if (playerNum == 1) {
        // Handle input for player 1 (e.g., WASD)
        switch (getch()) {
            case 'w': setVel(0, -1); break;
            case 'a': setVel(-1, 0); break;
            case 's': setVel(0, 1); break;
            case 'd': setVel(1, 0); break;
            case ' ': shoot(); break; // Space to shoot
        }
    } else if (playerNum == 2) {
        // Handle input for player 2 (e.g., arrow keys)
        switch (getch()) {
            case KEY_UP: setVel(0, -1); break;
            case KEY_LEFT: setVel(-1, 0); break;
            case KEY_DOWN: setVel(0, 1); break;
            case KEY_RIGHT: setVel(1, 0); break;
            case '0': shoot(); break; // Keypad 0 to shoot
        }
    }
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