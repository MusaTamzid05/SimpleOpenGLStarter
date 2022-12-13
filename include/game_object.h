#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <SFML/System/Vector3.hpp>

namespace Mutiny {
    struct GameObject {
        GameObject() {}
        virtual void update() = 0;
        virtual void render() = 0;

        sf::Vector3f  color;

    };
}

#endif
