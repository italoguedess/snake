cmake_minimum_required(VERSION 3.25.1)
project(Cobrita CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

add_executable(snake src/snake.cpp)

# include(CheckPIESupported)
# check_pie_supported()

add_subdirectory(src)
target_link_libraries(snake game)
target_link_libraries(snake CONAN_PKG::sfml)
# set_property(TARGET snake PROPERTY POSITION_INDEPENDENT_CODE TRUE)

# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")


# target_compile_options(snake PUBLIC "-pie")
