#include "scene.h"
#include "cube.h"
#include <SFML/OpenGL.hpp>
#include <iostream>

namespace  Mutiny {
    Scene::Scene(const std::string& title, int width, int height):
        window(sf::VideoMode(width, height), title, sf::Style::Default,
                sf::ContextSettings(24, 8, 4, 3, 0)) {
            window.setActive(true);
            running = true;
            window.setVerticalSyncEnabled(true);

            glewExperimental = GL_TRUE;

            if (glewInit() != GLEW_OK) {
                std::cerr << "glew error.\n";
                exit(1);
            }

            game_obejcts.push_back(new Cube());


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

        for(GameObject* game_object : game_obejcts)
            game_object->render();

        window.display();
    }

}
