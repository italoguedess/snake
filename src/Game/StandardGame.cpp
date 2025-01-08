#include "StandardGame.hpp"

// #include "Actor.hpp"
// #include "Scenario.hpp"

#include "Snake.hpp"
#include "PlainScenario.hpp"
#include "LogoDrawer.hpp"
#include "TitleDrawer.hpp"
#include "GameplayDrawer.hpp"
#include "EndDrawer.hpp"
#include "raylib.h"

#include <memory>
#include <iostream>


void StandardGame::start() noexcept {
    // actor_.reset(new Snake());
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic screen manager");

    actor_ = std::move(std::make_unique<Snake>());
    scenario_ = std::move(std::make_unique<PlainScenario>(20));
    drawers_[GameScenes::LOGO] = std::move(std::make_unique<LogoDrawer>(GetFontDefault(), GetFontDefault(), 20, 60));
    drawers_[GameScenes::TITLE] = std::move(std::make_unique<TitleDrawer>(GetFontDefault(), GetFontDefault(), 20, 60));
    drawers_[GameScenes::GAMEPLAY] = std::move(std::make_unique<GameplayDrawer>(*actor_.get(), *scenario_.get()));
    drawers_[GameScenes::END] = std::move(std::make_unique<EndDrawer>(GetFontDefault(), GetFontDefault(), 20, 60));

}

typedef enum GameScreen { LOGO = 0, TITLE, GAMEPLAY, ENDING } GameScreen;

void StandardGame::loop() noexcept {
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    int logo_counter = 0;
    int move_counter = 0;
    SetTargetFPS(60);               // Set desired framerate (frames-per-second)

    //--------------------------------------------------------------------------------------
    // Main game loop
    //--------------------------------------------------------------------------------------
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        //----------------------------------------------------------------------------------
        // Update
        //----------------------------------------------------------------------------------
        switch(game_scene_) {
            case GameScenes::LOGO: {
                // TODO: Update LOGO screen variables here!

                logo_counter++;

                // Wait for 2 seconds (120 frames) before jumping to TITLE screen
                if (logo_counter > 120)
                {
                    logo_counter = 0;
                    game_scene_ = GameScenes::TITLE;
                }
            } break;
            case GameScenes::TITLE: {
                // Getting access to specialized TitleDrawer methods
                const auto& title_drawer = static_cast<TitleDrawer *>(drawers_[GameScenes::TITLE].get());
                const auto& buttons = title_drawer->get_buttons();

                // Mouse hovering and clicking logic
                title_drawer->set_hovered_button(std::nullopt);
                for (const auto& [key, button] : buttons) {
                    if (CheckCollisionPointRec(GetMousePosition(), button.area)) {
                        title_drawer->set_hovered_button(key);

                        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
                            switch (key) {
                                case MenuButtons::START:
                                    game_scene_ = GameScenes::GAMEPLAY;
                                    break;
                                // case MenuButtons::SETTINGS:
                                //     game_scene_ = GameScenes::LOGO;
                                    break;
                                case MenuButtons::CREDITS:
                                    game_scene_ = GameScenes::LOGO;
                                    break;
                                case MenuButtons::EXIT:
                                    return;
                                    // game_scene_ = GameScenes::LOGO;
                                    break;
                            }
                        }
                    }
                }

            } break;
            case GameScenes::GAMEPLAY: {

                // Changing the snake direction
                // The snake cannot turn 180 degrees!!!
                if ((IsKeyDown(KEY_W) or IsKeyDown(KEY_UP)) and actor_->get_direction() != ActorDirections::DOWN) {
                    actor_->update_direction(ActorDirections::UP);
                } else if ((IsKeyDown(KEY_D) or IsKeyDown(KEY_RIGHT)) and actor_->get_direction() != ActorDirections::LEFT) {
                    actor_->update_direction(ActorDirections::RIGHT);
                } else if ((IsKeyDown(KEY_A) or IsKeyDown(KEY_LEFT)) and actor_->get_direction() != ActorDirections::RIGHT) {
                    actor_->update_direction(ActorDirections::LEFT);
                } else if ((IsKeyDown(KEY_S) or IsKeyDown(KEY_DOWN)) and actor_->get_direction() != ActorDirections::UP) {
                    actor_->update_direction(ActorDirections::DOWN);
                }

                // limitting the movement speed
                move_counter++;
                if (move_counter == 15) {
                    actor_->move();
                    move_counter = 0;
                }

                if (scenario_->get_food_position() == actor_->get_positions()[0]) {
                    scenario_->create_food();
                    actor_->grow();
                }

                // Press enter to change to ENDING screen
                if (IsKeyPressed(KEY_ENTER)
                    or IsGestureDetected(GESTURE_TAP)
                    or scenario_->is_out_of_bounds(actor_->get_positions()[0])
                    or actor_->is_self_eaten()) {
                    actor_->reset();
                    game_scene_ = GameScenes::END;
                }

            } break;
            case GameScenes::END: {
                // Press enter to return to TITLE screen
                if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP)) {
                    game_scene_ = GameScenes::TITLE;
                }
                break;

            }
            default: break;
        }

        //----------------------------------------------------------------------------------
        // Draw
        //----------------------------------------------------------------------------------

        switch(game_scene_) {
            case GameScenes::LOGO:
                drawers_[GameScenes::LOGO]->draw();
                break;
            case GameScenes::TITLE:
                drawers_[GameScenes::TITLE]->draw();
                break;
            case GameScenes::GAMEPLAY:
                drawers_[GameScenes::GAMEPLAY]->draw();
                break;
            case GameScenes::END:
                drawers_[GameScenes::END]->draw();
                break;
            default: break;
        }

    }
}

void StandardGame::end() noexcept {
    actor_.release();
    scenario_.release();
    for (auto& [key, drawer] : drawers_) {
        drawer.release();
    }
    CloseWindow();        // Close window and OpenGL context
}


void StandardGame::change_scene(const GameScenes game_scene) noexcept {
    game_scene_ = game_scene;
}
