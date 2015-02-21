/*
    Keep It Stupid Simple Engine

    Written by JohnBobSmith and
    muttstuffle, as a hobby project.

    Notice:
    You are free to use this code
    in any way you wish, provided
    you give credit to the original
    authors.
*/

#include <SFML/Graphics.hpp>
#include "headers/KPhysics.hpp"
int main()
{
    PhysicsObject * ball = new PhysicsObject();
    WorldPhysics * level1 = new WorldPhysics();
	level1->attachMember(ball);
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML TEST");
    sf::CircleShape circle(100.f);
    circle.setFillColor(sf::Color::Green);

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }
        window.clear();
        window.draw(circle);
        window.display();
    }
}
