#ifndef SNAKE_HPP_
#define SNAKE_HPP_

#include <cstdlib>

#include "Actor.hpp"

class Snake final : public Actor {
    public:
        // Default position is set to {1, 1} to account for the border
        Snake(const std::vector<std::array<int, 2>>& positions = {{2, 1}, {1, 1}},
              const size_t size = 1,
              ActorDirections direction = ActorDirections::RIGHT);


        void move() noexcept override;
        void grow() noexcept override;
        void reset() noexcept override;

        bool is_self_eaten() const noexcept override;
        void update_direction(ActorDirections direction) noexcept override;

        const std::vector<std::array<int, 2>>& get_positions() const noexcept;
        ActorDirections get_direction() const noexcept override;

    private:
        std::vector<std::array<int, 2>> positions_;
        size_t size_;
        ActorDirections direction_;
};


#endif // SNAKE_HPP_
