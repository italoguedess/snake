#include "game.hpp"

bool Game::is_out_of_bounds()
{
  // checks if the snake is positioned inside the grid
  if(this->grid.get_sprite().getGlobalBounds().contains(this->snake.get_position()))
    return false;
  else
    return true;
}

bool Game::is_food_eaten()
{
  // checks if the food sprite intersects the snake sprite
  if(this->grid.get_food().getGlobalBounds().intersects(this->snake.get_sprite().getGlobalBounds()))
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

Grid Game::get_grid(){return this->grid;}
void Game::set_grid(Grid new_grid){this->grid = new_grid;}

sf::Text Game::get_text(){return this->text;}
void Game::set_text(sf::Text new_text){this->text = new_text;}
