#ifndef GAMEPLAYDRAWER_HPP_
#define GAMEPLAYDRAWER_HPP_

#include "Drawer.hpp"
#include "Actor.hpp"
#include "Scenario.hpp"

class GameplayDrawer final : public Drawer {
    public:
        GameplayDrawer(const Actor& actor, const Scenario& scenario) noexcept;
        void draw() const noexcept;

    private:
        const Actor& actor_;
        const Scenario& scenario_;
};


#endif // GAMEPLAYDRAWER_HPP_
