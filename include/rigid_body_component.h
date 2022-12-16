#ifndef RIGIDBODY_COMPONENT_H
#define RIGIDBODY_COMPONENT_H

#include "component.h"
#include <glm/vec3.hpp>
#include <glm/gtc/quaternion.hpp>

namespace reactphysics3d {
    class RigidBody;
}

namespace Mutiny {
    struct GameObject;
    struct Scene;

    struct RigidBodyComponent : public Component {
        public:

            RigidBodyComponent(GameObject* game_object, Scene* scene);
            virtual ~RigidBodyComponent();


            void update(float delta_time);
            void render();

            reactphysics3d::RigidBody* body;



    };
}

#endif
