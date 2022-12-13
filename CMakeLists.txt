# This is the CMakeLists.txt file of the "hello world" project
# in order to show a simple executable that uses the ReactPhysics3D library

# Minimum cmake version required
cmake_minimum_required(VERSION 3.8)

# Help CMake to find the installed library on Windows
if(WIN32)
  list(APPEND CMAKE_PREFIX_PATH "C:\\Program Files (x86)\\ReactPhysics3D")
elseif(APPLE)
  list(APPEND CMAKE_PREFIX_PATH "/usr/local/lib/cmake/ReactPhysics3D")
endif()

# Import the ReactPhysics3D library that you have installed on your computer using
# the "make install" command
find_package(ReactPhysics3D REQUIRED)
set(CMAKE_BUILD_TYPE Debug)

set(
    SOURCE_FILES
    src/main.cpp
    src/shader.cpp
    src/game_object.cpp
    src/camera.cpp
    src/scene.cpp

    src/cube.cpp

    src/demos/simple_scene.cpp

    )

# Project
project(game_engine)

include_directories(include)

# Create the executable
add_executable(engine ${SOURCE_FILES})

# Link with the ReactPhysics3D library
target_link_libraries(engine ReactPhysics3D::ReactPhysics3D sfml-graphics sfml-window sfml-system GL GLEW)
