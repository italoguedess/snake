add_library(game core/game.cpp core/actor.cpp core/scenario.cpp)
target_link_libraries(game sfml-system)
target_link_libraries(game sfml-window)
target_link_libraries(game sfml-graphics)
