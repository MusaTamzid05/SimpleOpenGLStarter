#ifndef SCENE_H
#define SCENE_H

#include <string>
#include <SFML/Window.hpp>

namespace Mutiny {
    struct Scene {
        Scene(const std::string& title, int width = 1024, int height = 768);

        void start();
        void handle_event();
        void render();

        sf::Window window;
        bool running;
    };
}


#endif
