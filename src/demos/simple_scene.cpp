#include "demos/simple_scene.h"
#include "scene.h"
#include "cube.h"
#include "texture_manager.h"

namespace Demo {
    SimpleScene::SimpleScene(const std::string& title, int width, int height):Scene(title, width, height){
        Mutiny::TextureManager::get_instance()->add("../textures/container.jpg", "container");
        Mutiny::TextureManager::get_instance()->add("../textures/wall.jpg", "wall");
        game_objects.push_back(new Mutiny::Cube("container"));
    }
}
