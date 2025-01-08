#include <random>
#include <cstdlib>

#include "PlainScenario.hpp"


PlainScenario::PlainScenario(const size_t size) noexcept :
    size_(size) {
    create_food();
}

void PlainScenario::create_food() noexcept {
    std::random_device rd{};
    std::mt19937 gen(rd());
    // accounting for the borders
    std::uniform_real_distribution<double> dis(1, size_ - 2);
    // return dis(gen);
    food_position_ = {static_cast<int>(dis(gen)), static_cast<int>(dis(gen))};
}

bool PlainScenario::is_food_eaten(const std::array<int, 2>& position) const noexcept {
    return position == food_position_;
}

const std::array<int, 2>& PlainScenario::get_food_position() const noexcept {
    return food_position_;
}

bool PlainScenario::is_out_of_bounds(const std::array<int, 2>& position) const noexcept {
    if (position[0] < 0) {
        return true;
    } else if (position[0] > size_ - 3) {
        return true;
    }

    if (position[1] < 0) {
        return true;
    } else if (position[1] > size_ - 3) {
        return true;
    }

    return false;
}


size_t PlainScenario::get_size() const noexcept {
    return size_;
}
