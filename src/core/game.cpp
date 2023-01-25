#include "game.hpp"

bool Game::is_out_of_bounds()
{
  // checks if the snake is positioned inside the scenario
  if(this->scenario.get_sprite().getGlobalBounds().contains(this->snake.get_position()))
    return false;
  else
    return true;
}

bool Game::is_body_eaten()
{
  auto head_position = this->snake.get_position();
  auto f = [head_position](sf::Sprite elem)
    {return (head_position == elem.getPosition()) ? true : false;};
  const auto snake_body = this->snake.get_vector_sprite() | std::views::drop(1);
  if(std::ranges::any_of(snake_body, f))
    return true;
  else
    return false;
}

bool Game::is_food_eaten()
{
  // checks if the food sprite intersects the snake sprite
  if(this->scenario.get_food().getGlobalBounds().intersects(this->snake.get_sprite().getGlobalBounds()))
    return true;
  else
    return false;
}

bool Game::get_pause_state(){return this->pause_state;}
void Game::set_pause_state(bool new_pause_state){this->pause_state = new_pause_state;}

int Game::get_score(){return this->score;}
void Game::set_score(int new_score){this->score = new_score;}

Actor Game::get_snake(){return this->snake;}
void Game::set_snake(Actor new_snake){this->snake = new_snake;}

Scenario Game::get_scenario(){return this->scenario;}
void Game::set_scenario(Scenario new_scenario){this->scenario = new_scenario;}

sf::Text Game::get_text(){return this->text;}
void Game::set_text(sf::Text new_text){this->text = new_text;}
