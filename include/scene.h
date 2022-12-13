#ifndef SCENE_H
#define SCENE_H

#include <GL/glew.h>

#include <string>
#include <vector>
#include <SFML/Window.hpp>
#include "game_object.h"

namespace Mutiny {
    struct Scene {
        Scene(const std::string& title, int width = 1024, int height = 768);

        void start();
        void handle_event();
        void render();
        void update();

        sf::Window window;
        bool running;

        int width;
        int height;

        std::vector<GameObject*> game_obejcts;
    };
}


#endif
