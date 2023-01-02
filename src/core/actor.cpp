#include "actor.hpp"
#include <iostream>

void Snake::set_direction(char new_direction)
{
  this->direction = new_direction;
}

std::array<int, 2> Snake::get_position()
{
  return this->position;
}

void Snake::move()
{
  // The screen is thought as a matrix like
  //   |_|_|_|...
  //   |_|_|_|...
  //   |_|_|_|...
  //     ...
  // where the upper left position is the origin (0,0),
  // and the number of the line increases downwards
  // and the number of the column increases to the right
  switch (this->direction)
  {
    // if the direction is set upwards
    case 'w':
      // decreases the y coordinate
      this->position.at(1)--;
      break;
    case 's':
      // increases the y coordinate
      this->position.at(1)++;
      break;
    // if the direction is set to the right
    case 'd':
      // increases the x coordinate
      this->position.at(0)++;
      break;
    // if the direction is set to the left
    case 'a':
      // decreases the x coordinate
      this->position.at(0)--;
      break;
  }
}


void Snake::size_pp()
{
  this->size++;
}

int Snake::get_size()
{
  return this->size;
}
