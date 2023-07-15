cmake_minimum_required(VERSION 3.25.1)
project(SnakeGame CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

find_package(SFML REQUIRED)

add_executable($(PROJECT_NAME) src/snake.cpp)

# Make all executables be generated in the bin folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(src)
target_link_libraries(snake game)
target_link_libraries(snake SFML::SFML)
