#include "TitleDrawer.hpp"

#include <array>

TitleDrawer::TitleDrawer(const Font font, const Font header_font, const size_t font_size, const size_t header_font_size) noexcept :
    font_(font),
    header_font_(header_font),
    font_size_(font_size),
    header_font_size_(header_font_size),
    buttons_({
        {MenuButtons::START, {{}, "Start"}},
        // {MenuButtons::SETTINGS, {{}, "Settings"}},
        {MenuButtons::CREDITS, {{}, "Credits"}},
        {MenuButtons::EXIT, {{}, "Exit"}}
    }),
    hovered_button_(std::nullopt),
    buttons_spacing_(50) {

    create_buttons();
}

void TitleDrawer::draw() const noexcept {
  const unsigned int num_buttons = 2;
  std::array<std::string, num_buttons> buttons_text = {"Start Game", "Credits"};
  bool hover = true;

  BeginDrawing();
    ClearBackground(RAYWHITE);
    draw_centralized_text(header_font_, "Snek", header_font_size_, BLACK, 0, 50);
    draw_buttons();
  EndDrawing();
}

void TitleDrawer::set_hovered_button(std::optional<MenuButtons> hovered_button) noexcept {
    hovered_button_ = hovered_button;
}

const std::map<MenuButtons, Button>& TitleDrawer::get_buttons() const noexcept {
    return buttons_;
}

void TitleDrawer:: create_buttons() noexcept {
    int x_offset = 0, y_offset = buttons_spacing_;

    for (const auto& [key, button] : buttons_) {

        const float button_width = 200;
        const float button_height = font_size_ + 10;

        const Rectangle button_background = {
            static_cast<float>(GetScreenWidth()) / 2 + x_offset - static_cast<float>(button_width) / 2,
            static_cast<float>(GetScreenHeight()) / 2 + y_offset - static_cast<float>(button_height) / 2,
            button_width, button_height};


        buttons_[key].area = button_background;

        y_offset += buttons_spacing_;
    }

}

void TitleDrawer::draw_buttons() const noexcept {

    int x_offset = 0, y_offset = buttons_spacing_;

    for (const auto& [key, button] : buttons_) {

        DrawRectangleRec(button.area, (hovered_button_ == key) ? SKYBLUE : GRAY);
        DrawRectangleLinesEx(button.area, 1, DARKGRAY);

        draw_centralized_text(font_, button.text.c_str(), font_size_, BLACK, x_offset, -y_offset);;

        y_offset += buttons_spacing_;
    }
}
