#ifndef GAME_HPP
#define GAME_HPP

#include "scenario.hpp"
#include "actor.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <unordered_map>
#include <string>

struct Game_Interface
{
  virtual void start(const std::unordered_map<std::string, sf::Sprite> &sprites) = 0;
  virtual void run() = 0;
  virtual void pause() = 0;
  virtual void resume() = 0;
  virtual void config() = 0;
  virtual void quit() = 0;
};

class Game : public Game_Interface
{
  // enables game to be paused
  bool pause_state = false;
  // stores the score
  int score;
  // the game has one snake
  Actor snake;
  // each step the snake takes offsets its position by
  // its sprite width
  int move_step = 1;
  // the snake moves in a scenario
  Scenario scenario;
  // font
  sf::Text text;
  // window
  sf::RenderWindow window;

  bool is_out_of_bounds();
  bool is_body_eaten();
  bool is_food_eaten();

public:
  // getter and setter methods
  bool get_pause_state();
  void set_pause_state(bool new_pause_state);
  int get_score();
  void set_score(int new_score);
  Actor get_snake();
  void set_snake(Actor new_snake);
  Scenario get_scenario();
  void set_scenario(Scenario new_scenario);
  sf::Text get_text();
  void set_text(sf::Text new_text);

  virtual void start(const std::unordered_map<std::string, sf::Sprite> &sprites) override
  {
    // creates the game window
    this->window.create(sf::VideoMode(700, 700), "Snake Game");
    // loads the snake scenario and food sprites
    this->snake.set_sprite(sprites.at("snake"));
    this->scenario.set_sprite(sprites.at("scenario"));
    this->scenario.set_food(sprites.at("food"));
    this->scenario.set_bounds(sprites.at("bounds"));
    // move_step of actor is defined according to their texture width
    this->move_step = this->snake.get_sprite().getTextureRect().width;
    this->snake.set_position(sf::Vector2f(50, 50));
  }

  virtual void run() override
  {
    // interface to the snake actor
    Actor_Controls *actor_controls = &this->snake;
    this->scenario.random_position_food();
    while(this->window.isOpen())
    {
      sf::Event event;
      while (this->window.pollEvent(event))
      {
        if(event.type == sf::Event::Closed)
          this->quit();
        if(event.type == sf::Event::KeyReleased)
        {
          switch(event.key.code)
          {
            case sf::Keyboard::W:
                actor_controls->point_up();
              break;
            case sf::Keyboard::A:
              actor_controls->point_left();
              break;
            case sf::Keyboard::D:
              actor_controls->point_right();
              break;
            case sf::Keyboard::S:
              actor_controls->point_down();
              break;

          } // switch event key code
        } // if event::keyreleased
      } // while pollevent

      // clear the window with black color
      this->window.clear(sf::Color::Black);

      // draw everything here...
      actor_controls->move(move_step);

      if(this->is_out_of_bounds())
        this->window.close();
      if(this->is_body_eaten())
        this->window.close();
      if(this->is_food_eaten())
      {
        std::cout << "YES!" << std::endl;
        this->scenario.random_position_food();
        this->snake.grow();
      }
      // this->window.draw(this->scenario.get_sprite());
      // draw the scenario
      this->window.draw(this->scenario.get_bounds());
      this->window.draw(this->scenario.get_sprite());
      for(auto elem : this->snake.get_vector_sprite())
        this->window.draw(elem);
      this->window.draw(this->scenario.get_food());

      // end the current frame
      this->window.display();
      sf::sleep(sf::seconds(0.5));



    } // while window is open
  } // void start
  virtual void pause() override {this->pause_state = true;}
  virtual void resume() override {this->pause_state = false;}
  virtual void config() override {}
  virtual void quit() override {this->window.close();}
};

#endif
