#ifndef GAME_H
#define GAME_H

#include "GameEngine.h"

class Game
{
public:
    sf::Sprite ballSprite;

    Game();
    void handle_keyboard_input(sf::Event event);
    void move_ball();

private:
    sf::Texture ballTexture;
    sf::Vector2f ballVector;

    float ballVelocityX, ballVelocityY;
};

#endif // GAME_H
