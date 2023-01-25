#include "actor.hpp"
#include <iostream>
#include <algorithm>
#include <SFML/Graphics.hpp>

Actor::Actor(){this->sprite.emplace_back();}
// getter an setter methods

sf::Vector2f Actor::get_position(){return this->sprite.at(0).getPosition();}
void Actor::set_position(sf::Vector2f new_position)
{this->sprite.at(0).setPosition(new_position);}

char Actor::get_direction(){return this->direction;}
void Actor::set_direction(char new_direction)
{
  std::array<char, 4> valid_directions = {'w', 'a', 's', 'd'};
  // checks if new_direction is of the valid directions
  if(!std::ranges::any_of(valid_directions, [new_direction](char elem){return elem == new_direction;}))
    std::cout << "invalid direction passed to object of class Actor!" << std::endl;
  else
    this->direction = new_direction;
}

sf::Sprite Actor::get_sprite(){return this->sprite.at(0);}
void Actor::set_sprite(sf::Sprite new_sprite){this->sprite.at(0) = new_sprite;}

std::vector<sf::Sprite> Actor::get_vector_sprite(){return this->sprite;}
void Actor::set_vector_sprite(std::vector<sf::Sprite> new_vector_sprite){this->sprite = new_vector_sprite;}

void Actor::grow(){this->sprite.emplace_back(this->sprite.at(0));}

// interface methods
// void Actor::point_left() {this->direction = 'a';}
// void Actor::point_up(){this->direction = 'w';}
// void Actor::point_right(){this->direction = 'd';}
// void Actor::point_down(){this->direction = 's';}
// The x coordinate increases from top to bottom
// The y coordinate increases from left to right
// just like in a matrix
// void Actor::move()
// {
//   // the y coordinate is the first element of the position array
//   auto &y = this->position.at(1);
//   // the x coordinate is the first element of the position array
//   auto &x = this->position.at(0);
//   switch(this->direction)
//   {
//   case 'w':
//     y--;
//     break;

//   case 's':
//     y++;
//     break;

//   case 'a':
//     x--;
//     break;

//   case 'd':
//     x++;
//     break;
//   }
// }
