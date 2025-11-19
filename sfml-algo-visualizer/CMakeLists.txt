cmake_minimum_required(VERSION 3.10)

project(sfml-algo-visualizer)

set(CMAKE_CXX_STANDARD 11)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

include_directories(include)

file(GLOB SOURCES
    src/*.cpp
    src/algorithms/*.cpp
    src/utils.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)