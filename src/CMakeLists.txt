add_library(game core/game.cpp core/actor.cpp core/scenario.cpp)
target_link_libraries(game SFML::SFML)
