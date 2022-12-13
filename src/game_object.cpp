#include "game_object.h"
#include "camera.h"

namespace Mutiny {
    GameObject::~GameObject() {
        delete shader;
    }


    void GameObject::render() {

        if(shader != nullptr) {
            shader->use();
            shader->setMat4("projection", Camera::get_instance()->projection);
            shader->setMat4("view", Camera::get_instance()->get_view_matrix());

        }

    }
}
