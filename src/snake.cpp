#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
// #include <SFML/Keyboard.hpp>
#include "core/game.hpp"
#include <unordered_map>
#include <string>

// ISSUE: apparently can't load a file without its complete path
// ISSUE: texture does't load when called in a library

int main()
{
  Game game;
  sf::Texture snake_texture, food_texture, scenario_texture, bounds_texture;
  snake_texture.loadFromFile("/home/italo/Pictures/wallpapers/fauna.png");
  food_texture.loadFromFile("/home/italo/Pictures/20220314_20h39m21s_grim.png");
  scenario_texture.loadFromFile("/home/italo/Pictures/neos-card.png");
  bounds_texture.loadFromFile("/home/italo/Pictures/20220313_19h52m44s_grim.png");
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
