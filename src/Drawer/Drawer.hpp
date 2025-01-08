#ifndef DRAWER_HPP_
#define DRAWER_HPP_

#include <cstdlib>

#include "raylib.h"

struct Drawer {
    virtual void draw() const noexcept = 0;
    // void draw_centralized_text() const noexcept;
    void draw_centralized_text(const Font font, const char text[],
                               const size_t font_size, const Color color,
                               const int x_offset, const int y_offset) const noexcept;
    virtual ~Drawer() noexcept = default;
};


#endif // DRAWER_HPP_
