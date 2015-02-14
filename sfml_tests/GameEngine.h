#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <SFML/Graphics.hpp>
#include <string>

class GameEngine
{
    public:
        sf::Texture load_texture_from_disk(std::string path);
};

#endif // GAMEENGINE_H
