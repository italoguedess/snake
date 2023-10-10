// Libraries

#include "scenario.hpp"
#include <SFML/Graphics.hpp>

// Getters and setters

sf::Sprite Scenario::get_food(){return this->food;}
void Scenario::set_food(sf::Sprite new_food){this->food = new_food;}

sf::Sprite Scenario::get_sprite(){return this->sprite;}
void Scenario::set_sprite(sf::Sprite new_sprite){this->sprite = new_sprite;}

sf::Sprite Scenario::get_bounds(){return this->bounds;}
void Scenario::set_bounds(sf::Sprite new_bounds){this->bounds = new_bounds;}

// random_position_food

void Scenario::random_position_food()
{
  std::random_device rd;
  std::mt19937 gen(rd());
  // dis_x and dis_y are generated bounded by scenario sprite
  std::uniform_int_distribution<> dis_x(this->sprite.getGlobalBounds().left,
					this->sprite.getGlobalBounds().width);
  std::uniform_int_distribution<> dis_y(this->sprite.getGlobalBounds().top,
					this->sprite.getGlobalBounds().height);
  this->food.setPosition(dis_x(gen), dis_y(gen));
}
