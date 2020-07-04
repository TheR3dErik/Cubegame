cmake_minimum_required(VERSION 3.16)
project(VoxelGame)

set(CMAKE_CXX_STANDARD 17)
include_directories(include)

add_executable(VoxelGame main.cpp graphics/window.cpp graphics/window.h glad/src/glad.c math/vector.h math/matrix.h graphics/Model.cpp graphics/Model.h graphics/Shader.cpp graphics/Shader.h graphics/Camera.cpp graphics/Camera.h graphics/PerspectiveCamera.cpp graphics/PerspectiveCamera.h Chunk.cpp Chunk.h)

find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)
include_directories(${GLFW_INCLUDE_DIRS})
target_link_libraries(VoxelGame ${GLFW_LIBRARIES} GL X11 pthread Xrandr dl)
