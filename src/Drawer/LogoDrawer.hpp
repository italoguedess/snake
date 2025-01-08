#ifndef LOGODRAWER_HPP_
#define LOGODRAWER_HPP_

#include <cstdlib>

#include "raylib.h"

#include "Drawer.hpp"

class LogoDrawer final : public Drawer {
    public:
        LogoDrawer(const Font font, const Font header_font,  const size_t font_size, const size_t header_font_size) noexcept;
        void draw() const noexcept override;

    private:
        const Font font_;
        const Font header_font_;
        const size_t font_size_;
        const size_t header_font_size_;
};


#endif // LOGODRAWER_HPP_
