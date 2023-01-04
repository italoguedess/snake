#ifndef ACTOR_HPP
#define ACTOR_HPP
#include <array>

/*
 * Class which will implement all the
 * caracteristics and behaviours of
 * the actor
 */

class Snake
{
public:
  // sets the direction in which the snake is headed
  virtual void point_left() = 0;
  virtual void point_up() = 0;
  virtual void point_right() = 0;
  virtual void point_down() = 0;
  // makes the snake move one step
  virtual void move() = 0;
};

class Actor : public Snake
{
private:
  // snake's sizes initiates as 1
  int size = 1;
  // attribute which stores the x and y position
  // of the head of the snake
  std::array<int, 2> position = {0, 0};
  // the direction in which the snake will move
  char direction = 'w';
public:
  // getter an setter methods
  int get_size();
  void set_size(int new_size);
  std::array<int, 2> get_position();
  void set_position(std::array<int, 2> new_position);
  char get_direction();
  void set_direction(char new_direction);
  // interface methods
  void point_left();
  void point_up();
  void point_right();
  void point_down();
  void move();
};


#endif
