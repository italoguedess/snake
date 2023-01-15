#ifndef SCENARIO_HPP
#define SCENARIO_HPP

// #include <armadillo>
#include <array>
#include <random>
#include <SFML/Graphics.hpp>
#include <unordered_map>

/* Classes which will implement
 * the all scenario elements
 * like the borders and foo position
 */

struct Scenario
{
  // randomly positions the food
  virtual void random_position_food(sf::Vector2u window_size) = 0;
};

class Grid : public Scenario
{
private:
  // all possible positions
  int grid_size = 30;
  // grid
  // arma::mat<int, 30> grid;
  // food position in the grid
  sf::Sprite food;
  // sprite
  sf::Sprite sprite;
  std::unordered_map<std::string, sf::Sprite> sprites;
public:
  // getter and setter methods
  int get_grid_size();
  void set_grid_size(int new_grid_size);
  sf::Sprite get_food();
  void set_food(sf::Sprite new_food);
  sf::Sprite get_sprite();
  void set_sprite(sf::Sprite new_sprite);
  // interface methods
  // randomly positions the food inside window region
  virtual void random_position_food(sf::Vector2u window_size) override
  {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis_x(0, window_size.x);
    std::uniform_int_distribution<> dis_y(0, window_size.y);
    int x = dis_x(gen);
    int y = dis_y(gen);
    this->food.setPosition(x, y);
  }
};

#endif
