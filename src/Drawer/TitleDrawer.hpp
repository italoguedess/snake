#ifndef TITLEDRAWER_HPP_
#define TITLEDRAWER_HPP_

#include "Drawer.hpp"

#include <memory>
#include <string>
#include <map>
#include <vector>
#include <optional>

typedef enum class MenuButtons {
    START,
    CREDITS,
    EXIT
} MenuButtons;

typedef struct Button {
    Rectangle area;
    const std::string text;
} Button;

class TitleDrawer final : public Drawer {
    public:
        TitleDrawer(const Font font, const Font header_font,  const size_t font_size, const size_t header_font_size_) noexcept;
        void draw() const noexcept override;

        void set_hovered_button(std::optional<MenuButtons> hovered_button) noexcept;
        const std::map<MenuButtons, Button>& get_buttons() const noexcept;

    private:
        const Font font_;
        const Font header_font_;
        const size_t font_size_;
        const size_t header_font_size_;

        // Title menu buttons management
        std::map<MenuButtons, Button> buttons_;
        std::optional<MenuButtons> hovered_button_;
        const size_t buttons_spacing_;

        void draw_buttons() const noexcept;
        void create_buttons() noexcept;
};


#endif // TITLEDRAWER_HPP_
