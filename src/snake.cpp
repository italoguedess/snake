#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
// #include <SFML/Keyboard.hpp>
#include "core/game.hpp"
#include <unordered_map>
#include <string>

int main()
{
  Game game;
  sf::Texture snake_texture, food_texture, scenario_texture, bounds_texture;
  snake_texture.loadFromFile("../include/textures/alien_14.jpg");
  food_texture.loadFromFile("../include/textures/weird_alien_textures/alien_01_norm.jpg");
  scenario_texture.loadFromFile("../include/textures/grass.png");
  bounds_texture.loadFromFile("../include/textures/grassoverlay.png");
  sf::Sprite snake_sprite, food_sprite, scenario_sprite, bounds_sprite;
  snake_sprite.setTexture(snake_texture);
  food_sprite.setTexture(food_texture);
  snake_sprite.setTextureRect(sf::IntRect(50, 50, 50, 50));
  food_sprite.setTextureRect(sf::IntRect(50, 50, 50, 50));
  scenario_sprite.setTexture(scenario_texture);
  scenario_sprite.setTextureRect(sf::IntRect(600, 600, 600, 600));
  bounds_sprite.setTexture(bounds_texture);
  bounds_sprite.setTextureRect(sf::IntRect(700, 700, 700, 700));
  scenario_sprite.setPosition(50, 50);
  std::unordered_map<std::string, sf::Sprite> sprites_map ({{"snake", snake_sprite},
							    {"food", food_sprite},
							    {"scenario", scenario_sprite},
							    {"bounds", bounds_sprite}});

  game.start(sprites_map);
  game.run();

  return 0;
}
