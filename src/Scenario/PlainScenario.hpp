#ifndef PLAINSCENARIO_HPP_
#define PLAINSCENARIO_HPP_

#include <cstdlib>

#include "Scenario.hpp"

class PlainScenario final : public Scenario {
    public:
        PlainScenario(const size_t size) noexcept;
        void create_food() noexcept override;
        bool is_food_eaten(const std::array<int, 2>& position) const noexcept override;
        const std::array<int, 2>& get_food_position() const noexcept override;
        bool is_out_of_bounds(const std::array<int, 2>& position) const noexcept override;
        size_t get_size() const noexcept;

    private:
        const size_t size_;
        std::array<int, 2> food_position_;
};


#endif // PLAINSCENARIO_HPP_
