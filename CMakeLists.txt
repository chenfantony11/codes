cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 14)

project(Demo-C++)

aux_source_directory(./src/. SRC_LIST)

add_executable(${PROJECT_NAME} ${SRC_LIST})
