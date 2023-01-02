#ifndef ACTOR_HPP
#define ACTOR_HPP
#include <array>
#define interface struct

/*
 * Class which will implement all the
 * caracteristics and behaviours of
 * the actor
 */

interface Snake_Interface
{
  // sets the direction in which the snake is headed
  virtual void set_direction(char new_direction) = 0;
  // sets the direction in which the snake is headed
  virtual std::array<int, 2> get_position() = 0;
  // makes the snake move one step
  virtual void move() = 0;
  // increments the size of the snake
  virtual void size_pp() = 0;
  // gets the size of the snake
  virtual int get_size() = 0;
};

class Snake : public Snake_Interface
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
  // sets the direction in which the snake is headed
  virtual void set_direction(char new_direction);
  // sets the direction in which the snake is headed
  virtual std::array<int, 2> get_position();
  // makes the snake move one step
  virtual void move();
  // increments the size of the snake
  virtual void size_pp();
  // gets the size of the snake
  virtual int get_size();
};

#endif
