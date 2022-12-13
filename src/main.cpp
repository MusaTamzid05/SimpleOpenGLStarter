#include <reactphysics3d/reactphysics3d.h>
#include <iostream>


int main(int argc, char** argv) {
    reactphysics3d::PhysicsCommon physicsCommon;
    reactphysics3d::PhysicsWorld* world = physicsCommon.createPhysicsWorld();

    reactphysics3d::Vector3 position(0, 20, 0);
    reactphysics3d::Quaternion orientation = reactphysics3d::Quaternion::identity();
    reactphysics3d::Transform transform(position, orientation);
    reactphysics3d::RigidBody* body = world->createRigidBody(transform);


    const float time_step =   1.0f / 60.0f;

    for(int i = 0; i < 20; i += 1) {
        world->update(time_step);
        const reactphysics3d::Transform& transform=  body->getTransform();
        const reactphysics3d::Vector3& position =  transform.getPosition();

        std::cout << position.x << " " << position.y << " " << position.z << "\n";

    }

    return 0;
}
