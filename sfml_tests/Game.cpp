#include "GameEngine.h"
#include "Game.h"

Game::Game()
{
    GameEngine gameengine;
    ballTexture = gameengine.load_texture_from_disk("textures/ball.png");
    ballSprite.setTexture(ballTexture);
    ballVelocityX = 0.1;
    ballVelocityY = 0.1;
}

void Game::move_ball()
{
    ballSprite.move(ballVector);
}

void Game::handle_keyboard_input(sf::Event event)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        ballVector.x -= ballVelocityX;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        ballVector.x += ballVelocityX;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        ballVector.y += ballVelocityY;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        ballVector.y -= ballVelocityY;
    }
}

