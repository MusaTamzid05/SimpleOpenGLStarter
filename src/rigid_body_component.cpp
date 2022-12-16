#include "rigid_body_component.h"
#include "scene.h"
#include "game_object.h"
#include <reactphysics3d/reactphysics3d.h>

namespace Mutiny {
    RigidBodyComponent::RigidBodyComponent(
            GameObject* game_object,
            Scene* scene):
        Component(game_object) {

            // @TODO : we are not not using the orientation !!
            reactphysics3d::Vector3 body_position(game_object->position.x, game_object->position.y, game_object->position.z);
            reactphysics3d::Quaternion body_orientation = reactphysics3d::Quaternion::identity();
            reactphysics3d::Transform transform(body_position, body_orientation);
            body = scene->world->createRigidBody(transform);

            std::cout << "body is created\n";



    }

    RigidBodyComponent::~RigidBodyComponent() {

    }


    void RigidBodyComponent::update(float delta_time) {

        const reactphysics3d::Transform& transform=  body->getTransform();
        const reactphysics3d::Vector3& position =  transform.getPosition();
        const reactphysics3d::Quaternion& orientation = transform.getOrientation();

        game_object->position = glm::vec3(position.x, position.y, position.z);
        game_object->orientation = glm::quat(orientation.w, orientation.x, orientation.y, orientation.z);


    }


    void RigidBodyComponent::render() {

    }
}
