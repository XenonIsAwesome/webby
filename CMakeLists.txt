cmake_minimum_required(VERSION 3.28)
project(webby)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/missions/)

add_executable(${PROJECT_NAME}-server main.cpp)
target_link_libraries(${PROJECT_NAME}-server
        PUBLIC
        -Wl,--whole-archive
        ${PROJECT_NAME}-project1
        ${PROJECT_NAME}-project2

        -Wl,--no-whole-archive
        ${PROJECT_NAME}-lib
)