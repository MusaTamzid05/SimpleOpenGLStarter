#include "demos/simple_scene.h"
#include "scene.h"
#include "cube.h"
#include "texture_manager.h"

namespace Demo {
    SimpleScene::SimpleScene(const std::string& title, int width, int height):Scene(title, width, height){
        Mutiny::TextureManager::get_instance()->add("../textures/wall.jpg", "wall");
            game_obejcts.push_back(new Mutiny::Cube("wall"));
    }
}
