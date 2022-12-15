#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <SFML/System/Vector3.hpp>
#include "shader.h"

namespace Mutiny {

    struct GameObject {
        GameObject() {}
        virtual ~GameObject();
        virtual void update(float delta_time) = 0;
        virtual void render();

        sf::Vector3f  color;
        Shader* shader;



    };
}

#endif
