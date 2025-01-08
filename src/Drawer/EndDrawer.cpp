#include "EndDrawer.hpp"

#include "raylib.h"

EndDrawer::EndDrawer(const Font font, const Font header_font, const size_t font_size, const size_t header_font_size) noexcept :
    font_(font),
    header_font_(header_font),
    font_size_(font_size),
    header_font_size_(header_font_size){}

void EndDrawer::draw() const noexcept {

    BeginDrawing();
        ClearBackground(BLACK);
        char logo[] = "Game Over";
        char author[] = "Press ENTER to play again!";
        // DrawText(logo, 20, 20, 40, BLACK);
        draw_centralized_text(header_font_, logo, header_font_size_, RAYWHITE, 0, 20);
        draw_centralized_text(font_, author, font_size_, RAYWHITE, 0, -20);
        // DrawText(author, 20, 20, 40, BLACK);
    EndDrawing();

}
