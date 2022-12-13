#include "mtime.h"
#include <iostream>


namespace Mutiny {
    float MTime::delta_time = 0.0f;
    std::chrono::time_point<std::chrono::system_clock> MTime::previous_time = std::chrono::system_clock::now();

    void MTime::update() {
        std::chrono::time_point<std::chrono::system_clock> current_time = std::chrono::system_clock::now();
        std::chrono::duration<float> elasped_seconds = current_time - previous_time;
        delta_time = elasped_seconds.count();

        std::cout << delta_time << "\n";
        previous_time = current_time;
    }

}
