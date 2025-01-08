#include "Snake.hpp"

#include <algorithm>

Snake::Snake(const std::vector<std::array<int, 2>>& positions, const size_t size, ActorDirections direction):
    positions_(positions),
    size_(size),
    direction_(direction) {}

void Snake::move() noexcept {

    // updates the positions of the body by back propagation
    std::shift_right(begin(positions_), end(positions_), 1);

    // update the head position
    switch(direction_) {
        case ActorDirections::UP:
            positions_[0][1]--;
            break;
        case ActorDirections::LEFT:
            positions_[0][0]--;
            break;
        case ActorDirections::RIGHT:
            positions_[0][0]++;
            break;
        case ActorDirections::DOWN:
            positions_[0][1]++;
            break;
    }

}

void Snake::grow() noexcept {
    size_++;
    positions_.emplace_back(positions_.back());
}

void Snake::reset() noexcept {
    positions_ = {{2, 1}, {1, 1}};
    size_ = 2;
    direction_ = ActorDirections::RIGHT;
}

bool Snake::is_self_eaten() const noexcept {
    return std::find(begin(positions_) + 1, end(positions_), positions_[0]) != end(positions_);
}

void Snake::update_direction(ActorDirections direction) noexcept {
    direction_ = direction;
}


const std::vector<std::array<int, 2>>& Snake::get_positions() const noexcept {
    return positions_;
}

ActorDirections Snake::get_direction() const noexcept {
    return direction_;
}
