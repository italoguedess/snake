#ifndef ACTOR_HPP_
#define ACTOR_HPP_

#include <array>
#include <vector>

typedef enum class ActorDirections {
    UP,
    LEFT,
    RIGHT,
    DOWN
} ActorDirections;

struct Actor {
    virtual void move() noexcept = 0;
    virtual void grow() noexcept = 0;
    virtual void reset() noexcept = 0;
    virtual bool is_self_eaten() const noexcept = 0;
    virtual void update_direction(ActorDirections direction) noexcept = 0;
    virtual const std::vector<std::array<int, 2>>& get_positions() const noexcept = 0;
    virtual ActorDirections get_direction() const noexcept = 0;
    virtual ~Actor() = default;
};

#endif // ACTOR_HPP_
