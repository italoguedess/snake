#include "GameplayDrawer.hpp"

#include "raylib.h"

GameplayDrawer::GameplayDrawer(const Actor& actor, const Scenario& scenario) noexcept:
    actor_(actor),
    scenario_(scenario) {}

void GameplayDrawer::draw() const noexcept {
    const size_t scenario_size = scenario_.get_size();

    // logic needed so that the gameplay scene is squared despite the window measures
    const float l = (GetScreenWidth() < GetScreenHeight()) ? GetScreenWidth() : GetScreenHeight();

    // Diving the screen in the square units
    const float rect_width = l / scenario_size;
    const float rect_height = l / scenario_size;

    // calculating the offset to centralize the square
    const float width_centralizing_offset = (GetScreenWidth() < GetScreenHeight()) ? rect_width : (l / 2) - rect_width;
    const float height_centralizing_offset = (GetScreenWidth() < GetScreenHeight()) ? (l / 2) - rect_height : rect_height;

    const auto& actor_pos = actor_.get_positions();
    const auto& food_pos = scenario_.get_food_position();

    BeginDrawing();
        ClearBackground(DARKBLUE);

        // Draw scenario
        DrawRectangle(width_centralizing_offset,
                      height_centralizing_offset,
                      (scenario_size - 2) * rect_width,
                      (scenario_size - 2) * rect_height,
                      DARKBROWN);

        for (const auto& pos : actor_pos) {
            DrawRectangle(pos[0] * rect_width + width_centralizing_offset,
                          pos[1] * rect_height + height_centralizing_offset,
                          rect_width,
                          rect_height,
                          DARKGREEN);

        }

        DrawRectangle(food_pos[0] * rect_width + width_centralizing_offset,
                      food_pos[1] * rect_height + height_centralizing_offset,
                      rect_width,
                      rect_height,
                      MAROON);
    EndDrawing();
}
