#include "demos/simple_scene.h"
#include "scene.h"
#include "cube.h"

namespace Demo {
    SimpleScene::SimpleScene(const std::string& title, int width, int height):Scene(title, width, height){
            game_obejcts.push_back(new Mutiny::Cube());
    }
}
