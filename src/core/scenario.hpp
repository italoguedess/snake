#ifndef SCENARIO_HPP
#define SCENARIO_HPP

#include <armadillo>
#include <array>
#include <SFML/Window.hpp>

/* Classes which will implement
 * the all scenario elements
 * like the borders and foo position
 */

#define interface struct

interface Scenario_Interface
{
  // start scenario
  virtual void start() = 0;
  // another step in the program
  // the snake moves and food
  // is generated randomly
  virtual void update() = 0;
};

class Scenario : public Scenario_Interface
{
private:
  // all possible positions
  int grid_size = 30;
  // food position in the grid
  std::array<int, 2> food_position;
  // randomly positions the food
  void food_random_position();
public:
  // start scenario
  void start();
  // another step in the program:
  // the snake moves and food
  // is generated randomly
  void update();
};

#endif
