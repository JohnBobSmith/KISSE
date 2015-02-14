#include "GameEngine.h"
#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    Game game;
    int screenWidth = 640;
    int screenHeight = 480;

    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "SFML Tests");
    sf::Event event;

    window.setFramerateLimit(60);

    while(window.isOpen()){
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
            game.handle_keyboard_input(event);
        }
        window.clear(sf::Color::Black);
        game.move_ball();
        window.draw(game.ballSprite);
        window.display();
    }
}
