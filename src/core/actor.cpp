#include "actor.hpp"
#include <iostream>
#include <algorithm>

// getter an setter methods
int Actor::get_size(){return this->size;}
void Actor::set_size(int new_size){this->size = new_size;}

std::array<int, 2> Actor::get_position(){return this->position;}
void Actor::set_position(std::array<int, 2> new_position)
  {this->position = new_position;}

char Actor::get_direction(){return this->direction;}
void Actor::set_direction(char new_direction)
{
  std::array<char, 4> valid_directions = {'w', 'a', 's', 'd'};
  // checks if new_direction is of the valid directions
  if(!std::any_of(valid_directions.begin(), valid_directions.end(), [new_direction](char elem){return elem == new_direction;}))
    std::cout << "invalid direction passed to object of class Actor!" << std::endl;
  else
    this->direction = new_direction;
}

// interface methods
void Actor::point_left() {this->direction = 'a';}
void Actor::point_up(){this->direction = 'w';}
void Actor::point_right(){this->direction = 'd';}
void Actor::point_down(){this->direction = 's';}
// The x coordinate increases from top to bottom
// The y coordinate increases from left to right
// just like in a matrix
void Actor::move()
{
  // the y coordinate is the first element of the position array
  auto &y = this->position.at(1);
  // the x coordinate is the first element of the position array
  auto &x = this->position.at(0);
  switch(this->direction)
  {
  case 'w':
    y--;
    break;

  case 's':
    y++;
    break;

  case 'a':
    x--;
    break;

  case 'd':
    x++;
    break;
  }
}
