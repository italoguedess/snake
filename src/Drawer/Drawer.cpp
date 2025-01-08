#include "Drawer.hpp"

void Drawer::draw_centralized_text(const Font font, const char text[],
                                   const size_t font_size, const Color color,
                                   const int x_offset, const int y_offset) const noexcept {

    Vector2 text_size = MeasureTextEx(GetFontDefault(), text, font_size, 1);

    DrawText(text, (GetScreenWidth() - text_size.x) / 2 + x_offset,
        (GetScreenHeight() - text_size.y) / 2 - y_offset, font_size, color);
}
