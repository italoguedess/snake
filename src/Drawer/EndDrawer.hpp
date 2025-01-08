#ifndef ENDDRAWER_HPP_
#define ENDDRAWER_HPP_

#include <cstdlib>

#include "raylib.h"

#include "Drawer.hpp"

class EndDrawer final : public Drawer {
    public:
        EndDrawer(const Font font, const Font header_font,  const size_t font_size, const size_t header_font_size) noexcept;
        void draw() const noexcept override;

    private:
        const Font font_;
        const Font header_font_;
        const size_t font_size_;
        const size_t header_font_size_;
};

#endif // ENDDRAWER_HPP_
