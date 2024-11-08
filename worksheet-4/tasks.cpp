#include "game_of_life.hpp"
using namespace gol;
// Task 1: Implement the rule one function
void rule_one(int x, int y)
{
  if (!get_cell(x, y))
  {
    if (num_of_neigbours(x, y) < 2)
    {
      set_cell(x, y, false);
    }
  }
}
// Task 2: Implement the rule one function
void rule_two(int x, int y)
{
  if (get_cell(x, y))
  {
    if ((num_of_neigbours(x, y) == 2) || (num_of_neigbours(x, y) == 3))
    {
      set_cell(x, y, true);
    }
  }
}
// Task 3: Define and implement the rule three function
void rule_three(int x, int y)
{
  if (get_cell(x, y))
  {
    if (num_of_neigbours(x, y) > 3)
    {
      set_cell(x, y, false);
    }
  }
}
// Task 4: Define and implement the rule four function
void rule_four(int x, int y)
{
  if (!get_cell(x, y))
  {
    if ((num_of_neigbours(x, y) == 3) && (get_cell(x, y) == false))
    {
      set_cell(x, y, true);
    }
  }
}
//task 5
void my_gol()
{
  init_game_of_life("task_5.gif");
  seed_grid();
  write_frame();

  int num_frames = 200;
  for (size_t i = 0; i < num_frames; i++)
  {
    for (size_t j = 0; j < get_x_dimension(); j++)
    {
      for (size_t k = 0; k < get_y_dimension(); k++)
      {
        rule_one(j, k);
        rule_two(j, k);
        rule_three(j, k);
        rule_four(j, k);
      }
    }
    write_frame();
  }
  render();
}

int main()
{

  // // This is a test function: Highlight this block and use ctrl/cmd + /
  // // to uncommment the gol::run_gol function to test your functions.
  // // Note task 5 is below!
  //run_gol(rule_one, rule_two, rule_three, rule_four);
  my_gol();
  // Task 5: Using the functions available in game_of_life.hpp and
  // the pseudocode in worksheet 4, implement the main program code to
  // traverse the grid, apply your functions and generate the Gif
  //See this projects readme for details on the gol library.

  return 0;
}
