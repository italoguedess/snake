cmake_minimum_required(VERSION 3.15)
project(snake CXX)
set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} src/main.cpp)


install(TARGETS snake DESTINATION "."
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )


###################################################################################
# Game lib
###################################################################################
add_library(GAME src/Game/StandardGame.cpp)
target_include_directories(GAME PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/Game)
target_include_directories(GAME PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/Actor)
target_include_directories(GAME PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/Scenario)
target_include_directories(GAME PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/Drawer)
target_link_libraries(${PROJECT_NAME} PUBLIC GAME)


###################################################################################
# Actor lib
###################################################################################
add_library(ACTOR src/Actor/Snake.cpp)
# target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/Actor)
target_link_libraries(GAME PUBLIC ACTOR)


###################################################################################
# Scenario lib
###################################################################################
add_library(SCENARIO src/Scenario/PlainScenario.cpp)
# target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/Scenario)
target_link_libraries(GAME PUBLIC SCENARIO)

###################################################################################
# Drawer lib
###################################################################################
add_library(DRAWER src/Drawer/Drawer.cpp src/Drawer/LogoDrawer.cpp src/Drawer/EndDrawer.cpp src/Drawer/TitleDrawer.cpp src/Drawer/GameplayDrawer.cpp)
# target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/Drawer)
target_include_directories(DRAWER PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/Actor)
target_include_directories(DRAWER PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/Scenario)
target_link_libraries(GAME PUBLIC DRAWER)


###################################################################################
# Raylib
###################################################################################
find_package(raylib REQUIRED)
# target_include_directories(${PROJECT_NAME} PUBLIC ${raylib_INCLUDE_DIRS})
target_link_libraries(DRAWER PUBLIC raylib)
target_link_libraries(GAME PUBLIC raylib)
