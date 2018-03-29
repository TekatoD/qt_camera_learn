cmake_minimum_required(VERSION 3.9)
project(q_camera)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC  ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets)
find_package(Qt5Core)
find_package(Qt5Multimedia)
find_package(Qt5MultimediaWidgets)

set(SOURCE_FILES
        main.cpp camera.cpp camera.h camera_i.cpp camera_i.h)

add_executable(q_camera ${SOURCE_FILES})

target_link_libraries(q_camera
        Qt5::Core
        Qt5::Widgets
        Qt5::Multimedia
        Qt5::MultimediaWidgets)

