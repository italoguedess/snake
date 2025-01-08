#ifndef STANDARDGAME_HPP_
#define STANDARDGAME_HPP_

#include "Game.hpp"

class StandardGame final : public Game {
    public:
        StandardGame() noexcept = default;
        void start() noexcept override;
        void loop() noexcept override;
        void end() noexcept override;
        virtual void change_scene(const GameScenes game_scene) noexcept;
};


#endif // STANDARDGAME_HPP_
