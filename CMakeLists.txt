cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 20)

project(what2do)

add_executable(${PROJECT_NAME} main.cpp cli.cpp to_do.cpp temp_to_do_model.cpp)