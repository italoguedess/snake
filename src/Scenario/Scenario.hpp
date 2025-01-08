#ifndef SCENARIO_HPP_
#define SCENARIO_HPP_

#include <array>
#include <cstdlib>

struct Scenario {
    virtual void create_food() noexcept = 0;
    virtual bool is_food_eaten(const std::array<int, 2>& position) const noexcept = 0;
    virtual const std::array<int, 2>& get_food_position() const noexcept = 0;
    virtual bool is_out_of_bounds(const std::array<int, 2>& position) const noexcept = 0;
    virtual size_t get_size() const noexcept = 0;
    virtual ~Scenario() noexcept = default;
};


#endif // SCENARIO_HPP_
