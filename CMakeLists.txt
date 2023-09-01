cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 20)

project(what2do)

set(CMAKE_PREFIX_PATH /home/daniel/Qt/6.5.2/gcc_64/)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

qt_add_executable(what2do main.cpp to_do.cpp mainwindow.cpp temp_to_do_model.cpp)

target_link_libraries(what2do PRIVATE Qt6::Widgets)