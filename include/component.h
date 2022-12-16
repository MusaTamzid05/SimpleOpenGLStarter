#ifndef COMPONENT_H
#define COMPONENT_H


namespace Mutiny {
    struct GameObject;
    struct Component {
        Component(GameObject* game_object) {this->game_object = game_object;}
        virtual ~Component() {}

        virtual void update(float delta_time) = 0;
        virtual void render() = 0;

        GameObject* game_object;


    };
}

#endif
