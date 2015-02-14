#include "GameEngine.h"
#include <iostream>

sf::Texture GameEngine::load_texture_from_disk(std::string path)
{
    sf::Texture tempTexture;
    if(!tempTexture.loadFromFile(path.c_str())){
        std::cout << "Failed to load " << path;
    }

    return tempTexture;
}
