#ifndef ACTOR_HPP
#define ACTOR_HPP
#include <array>
#include <SFML/Graphics.hpp>
#include <iostream>

/*
 * Class which will implement all the
 * caracteristics and behaviours of
 * the actor
 */

struct Actor_Controls
{
  // sets the direction in which the snake is headed
  virtual void point_left() = 0;
  virtual void point_up() = 0;
  virtual void point_right() = 0;
  virtual void point_down() = 0;
  // makes the snake move one step
  virtual void move(const int move_step) = 0;
};

class Actor : public Actor_Controls
{
private:
  // number of members (head and body) the snake has
  int size = 1;
  // the direction in which the snake will move
  char direction = 'd';
  // Actor's sprite
  sf::Sprite sprite;
public:
  // getter an setter methods
  int get_size();
  void set_size(int new_size);
  sf::Vector2f get_position();
  void set_position(sf::Vector2f new_position);
  char get_direction();
  void set_direction(char new_direction);
  sf::Sprite get_sprite();
  void set_sprite(sf::Sprite new_sprite);
  // Snake_Back_End methods
  virtual void point_left() override {this->direction = 'a';}
  virtual void point_up() override {this->direction = 'w';}
  virtual void point_right() override {this->direction = 'd';}
  virtual void point_down() override {this->direction = 's';}
  virtual void move(const int move_step = 1) override
  {
    // offsets the position according to the direction
    if(move_step <= 0)
      std::cout << "in actor::move parameter move_step must be >= 0!" << std::endl;
    switch(this->direction)
    {
    case 'w':
      this->sprite.move(0, -1*move_step);
      break;
    case 's':
      this->sprite.move(0, move_step);
      break;
    case 'a':
      this->sprite.move(-1*move_step, 0);
      break;
    case 'd':
      this->sprite.move(move_step, 0);
      break;
    }
  }

};


#endif
