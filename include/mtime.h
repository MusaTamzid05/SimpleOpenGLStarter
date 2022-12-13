#ifndef MTIME_H
#define MTIME_H

#include <chrono>
namespace Mutiny {
    struct MTime {

        static void update();
        static float delta_time;

        static std::chrono::time_point<std::chrono::system_clock> previous_time;

    };
}
#endif
