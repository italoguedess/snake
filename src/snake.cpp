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
  sf::Texture snake_texture, scenario_texture;
  snake_texture.loadFromFile("/home/italo/Pictures/wallpapers/fauna.png");
  scenario_texture.loadFromFile("/home/italo/Pictures/neos-card.png");
  sf::Sprite snake_sprite, scenario_sprite;
  snake_sprite.setTexture(snake_texture);
  snake_sprite.setTextureRect(sf::IntRect(50, 50, 50, 50));
  scenario_sprite.setTexture(scenario_texture);
  scenario_sprite.setTextureRect(sf::IntRect(600, 600, 600, 600));
  scenario_sprite.setPosition(50, 50);
  std::unordered_map<std::string, sf::Sprite> sprites_map ({{"snake", snake_sprite},
                                                            {"scenario", scenario_sprite}});

  game.start(sprites_map);
  game.run();

  return 0;
}
