#include "scene.h"
#include "camera.h"
#include "cube.h"
#include <SFML/OpenGL.hpp>
#include <iostream>

namespace  Mutiny {
    Scene::Scene(const std::string& title, int width, int height):
        window(sf::VideoMode(width, height), title, sf::Style::Default,
                sf::ContextSettings(24, 8, 4, 3, 0)),
        width(width),
        height(height) {
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

            if(event.type == sf::Event::KeyPressed) {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) 
                    Camera::get_instance()->process_keyboard(CameraMovement::FORWARD);
                

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                    Camera::get_instance()->process_keyboard(CameraMovement::BACKWARD);

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                    Camera::get_instance()->process_keyboard(CameraMovement::LEFT);

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                    Camera::get_instance()->process_keyboard(CameraMovement::RIGHT);

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                    Camera::get_instance()->process_keyboard(CameraMovement::UP);

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                    Camera::get_instance()->process_keyboard(CameraMovement::DOWN);

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4))
                       Camera::get_instance()->rotate(-Camera::keyboard_rotation_speed, 0.0f, true);

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6))
                       Camera::get_instance()->rotate(Camera::keyboard_rotation_speed, 0.0f, true);

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8))
                       Camera::get_instance()->rotate(0.0f, Camera::keyboard_rotation_speed, true);

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2))
                       Camera::get_instance()->rotate(0.0f, -Camera::keyboard_rotation_speed, true);
            }
        }
    }

    void Scene::render() {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        for(GameObject* game_object : game_obejcts)
            game_object->render();

        window.display();
    }

    void Scene::update() {
        Camera::get_instance()->update();
    }

}
