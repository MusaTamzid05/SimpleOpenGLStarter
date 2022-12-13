#include "scene.h"
#include <SFML/OpenGL.hpp>
#include <iostream>

namespace  Mutiny {
    Scene::Scene(const std::string& title, int width, int height):
        window(sf::VideoMode(width, height), title, sf::Style::Default, sf::ContextSettings(32)) {
        window.setActive(true);
        running = true;
        window.setVerticalSyncEnabled(true);

    }

    void Scene::start() {

        while(running) {
            handle_event();
            render();
        }
    }

    void Scene::handle_event() {
        sf::Event event;

        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                running = false;
        }
    }

    void Scene::render() {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        window.display();
    }

}
