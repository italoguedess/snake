#include "LogoDrawer.hpp"

#include "raylib.h"

LogoDrawer::LogoDrawer(const Font font, const Font header_font, const size_t font_size, const size_t header_font_size) noexcept :
    font_(font),
    header_font_(header_font),
    font_size_(font_size),
    header_font_size_(header_font_size){}

void LogoDrawer::draw() const noexcept {

    BeginDrawing();
        ClearBackground(RAYWHITE);
        char logo[] = "Snake Game";
        char author[] = "Italo Guedes @github.com/italoguedess";
        // DrawText(logo, 20, 20, 40, BLACK);
        draw_centralized_text(header_font_, logo, header_font_size_, BLACK, 0, 20);
        draw_centralized_text(font_, author, font_size_, BLACK, 0, -20);
        // DrawText(author, 20, 20, 40, BLACK);
    EndDrawing();

}
