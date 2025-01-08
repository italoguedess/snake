#ifndef GAME_HPP_
#define GAME_HPP_

#include <memory>
#include <map>

#include "Actor.hpp"
#include "Scenario.hpp"
#include "Drawer.hpp"

typedef enum class GameScenes {
    LOGO,
    TITLE,
    GAMEPLAY,
    END
} GamesScenes;

class Game {
    public:
        virtual void start() noexcept = 0;
        virtual void loop() noexcept = 0;
        virtual void end() noexcept = 0;
        virtual void change_scene(const GameScenes game_scene) noexcept = 0;
        virtual ~Game() = default;

    protected:
        std::unique_ptr<Actor> actor_;
        std::unique_ptr<Scenario> scenario_;
        GameScenes game_scene_;
        std::map<GameScenes, std::unique_ptr<Drawer>> drawers_;
};


#endif // GAME_HPP_
