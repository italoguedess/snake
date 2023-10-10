// Beginning and libraries

#ifndef SCENARIO_HPP
#define SCENARIO_HPP

// #include <armadillo>
#include <array>
#include <random>
#include <SFML/Graphics.hpp>
#include <unordered_map>

// Scenario class
// Class which will implement all scenario elements like the borders and food.


class Scenario
{

// Attributes

private:
  // scenario sprite
  sf::Sprite sprite;
  // food sprite
  sf::Sprite food;
  // bounds sprite
  sf::Sprite bounds;

// Methods

public:
  // getter and setter methods
  sf::Sprite get_sprite();
  void set_sprite(sf::Sprite new_sprite);
  sf::Sprite get_food();
  void set_food(sf::Sprite new_food);
  sf::Sprite get_bounds();
  void set_bounds(sf::Sprite new_bounds);
  // interface methods
  // randomly positions the food inside window region
  void random_position_food();
};

#endif
