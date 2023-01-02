cmake_minimum_required(VERSION 2.8.12)
project(Cobrita CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
add_subdirectory(src)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

add_executable(snake src/snake.cpp)
# target_link_libraries(snake ${CONAN_LIBS})
target_link_libraries(snake CONAN_PKG::armadillo)
target_link_libraries(snake CONAN_PKG::sfml)
target_link_libraries(snake game)
# target_link_libraries(game ${CONAN_LIBS})
