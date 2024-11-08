# Conway's Game of Life

In this practical we implement the rules to Conway's game of life.

_You can find build and git reminders at the bottom of this readme...__

In this practical, we will generate gif's which animate conways game of life.

![game of life](example.gif)

## Gol Library

### Namespace
Any functions that are used from game_of_life.hpp will require access via the ```gol``` namespace. We use the scope operator ```::``` to apply this, so all functions are prepended with ```gol::``` meaning function calls look like this:
```c++
  gol::init_game_of_life();
```
Alternatively, ```using namespace gol;``` can be added above main.

## Functions

### ```gol::init_game_of_life(std::string file_name)```
_Must_ be called before using any other gol functions.
This function initialises the Game of Life grid and gif writing.

A file name can be passed in to provide a name for your gif.

### ```gol::seed_grid()```
Seed grid can be called to use this libraries seeding system - described below. this avoids needing to make many manual calls to ```set_cell()``` and speeds up making interesting start states.

### ```gol::write_frame()```
Writes the current grid to a gif frame. This should be called after modifying cells to render the grid to a frame (for as many frames as you want.)

### ```gol::render()```
Renders the gif from the frames that have been written using write_frame.
This should be called after initialisation of GoL and after writing all required frames.

### ```gol::num_of_neigbours(int x, int y)```
Returns an integer representing the number of neigbours the cell at the provided x and y position has. You should ensure that x and y do not exceed the bounds of the grid which you can check using the get_x_dimension() and get_y_dimension() respectively.

### ```gol::get_x_dimension()```
returns the size of the x dimension of the GoL grid.
This can be modified in the gif_config.hpp file by changing the GRID_X constant.
### ```gol::get_y_dimension()```
returns the size of the y dimension of the GoL grid.
This can be modified in the gif_config.hpp file by changing the GRID_Y constant.

### ```gol::get_cell(int x, int y)```
Returns a boolean indicating whether the cell at the provided position is 'alive' or 'dead'

### ```gol::set_cell(int x, int y, bool value)```
Set cell allows you to set whether the cell at the provided position is 'alive' or 'dead'. X and y provide the position and the boolean is true for 'alive' and and 'false' for dead.

# Game of Life
Check out the Game of Life wiki:
https://www.conwaylife.com/wiki/Main_Page

From here you can search the patterns that have been discovered and even access txt representations of them.

You can use the format ```.``` to represent an empty cell and ```O```(capital o) to represent a live cell. This format follows the GoL wiki's plain text format for ease of integration with our gif generator.

You can define your start state in the start_grid.txt file.

Use, two numbers seperated by spaces to provide coordinates for the living cells. Alternatively, you can provide a pattern by adding a file to the patterns directory and using a command with the following form:
```
pattern 1 1 example.txt
``` 
where pattern is a key word, the following numbers are the position to place the pattern and the final argument is the file name. Each commmand shoudl be space separated.

Follow the rules, this is not an overly robust parser!

Some patterns are baked in and can be run with just the name and coordinates:
```
glider 2 2
pulsar 2 2
beacon 2 2
sauron 2 2
```

# WorkFlow
## Building and running

> Remember to launch with VS developer prompt (on Windows)

Navigate into the worksheet4_tasks directory. (Build will not work if you try to build from a directory outside of this one.)

Build (```ctrl/cmd + shift + b```) and select the appropriate compiler for your platform.

To run, open a terminal window and use ```.\tasks.exe``` on windows and ```./tasks``` on mac and linux.

## Git

To save some changes and push to gitlab:
```
git add .
git commit -m "write your message in the quotes"
git push
```
