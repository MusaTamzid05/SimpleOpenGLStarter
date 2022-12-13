#ifndef CUBE_H
#define CUBE_H


#include "game_object.h"
#include "shader.h"

namespace Mutiny {
    struct Cube : GameObject {
        Cube();
        virtual ~Cube();
        void update(float delta_time);
        void render();

        unsigned int VAO;
        unsigned int VBO;

        Shader* shader; // gone use a shader factoty for that

    };
}

#endif
