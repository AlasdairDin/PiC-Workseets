#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include <sstream>
#include <functional>
#include "gif.h"
#include "gif_config.hpp"

namespace gol {

  int num_of_neigbours(int x, int y);
  bool get_cell(int x, int y);
  void set_cell(int x, int y, bool value);

namespace internal{

  GifWriter g;
  //std::vector< std::vector<bool> > grid(GRID_X + 2, std::vector<bool>(GRID_Y + 2,false));
  //std::vector< std::vector<bool> > prev_grid(GRID_X + 2, std::vector<bool>(GRID_Y + 2,false));

  bool grid[GRID_X + 2][GRID_Y + 2];
  bool prev_grid[GRID_X + 2][GRID_Y + 2];

  std::tuple<int, int> parse_line(std::string line){
    
    std::stringstream ss(line);
    std::string s;
    std::vector<int> nums;

    while (getline(ss, s,' ')) {
        nums.push_back(stoi(s));
    }
    return std::make_tuple(nums[0],nums[1]);
  }

  void seed_ascii(int x, int y, std::string file_path){

  std::string line;
  std::ifstream seed_pattern("patterns/"+file_path);
  
  int line_count = y;
  if(seed_pattern.is_open()){
    while( getline(seed_pattern,line)){
      if(line.length() < GRID_X)
        for (size_t i = 0; i < line.length(); i++){
          if(line[i] == 'O'){
            internal::grid[x+i][line_count] = true;
          }
        }
      if(line_count < GRID_Y)
        line_count++;
    }
    seed_pattern.close();
  } else std::cout << "Unable to open pattern file:" << file_path << '\n';

  }

  void add_preset(std::string line){
    
    std::stringstream ss(line);
    std::string s;
    std::vector<std::string> command;

    while (getline(ss, s,' ')) {
        command.push_back(s);
    }
    
    if(command.size() != 3 && command.size() != 4)
      return;

    if(command[0] == "pattern"){
      seed_ascii(stoi(command[1]),stoi(command[2]),command[3]);
    }else if(command[0] == "glider"){
      seed_ascii(stoi(command[1]),stoi(command[2]),"glider.cells");
    } else if(command[0] == "beacon"){
      seed_ascii(stoi(command[1]),stoi(command[2]),"beacon.cells");
    } else if(command[0] == "pulsar"){
      seed_ascii(stoi(command[1]),stoi(command[2]),"pulsar.cells");
    } else if(command[0] == "sauron"){
      seed_ascii(stoi(command[1]),stoi(command[2]),"sauron.cells");
    } else {
      std::cout << "! >> Unknown command found in seed file << ! \n";
    }
  }

  void clear_grid(){
      for (size_t i = 0; i < GRID_X + 2; i++){
      for (size_t j = 0; j < GRID_Y + 2; j++){ 
        internal::grid[i][j] = 0;
      }
    }
  }

  void ex_1(int x, int y){
    if(!gol::get_cell(x,y))
      return;
    if(gol::num_of_neigbours(x,y) < 2){
      gol::set_cell(x, y, false);
    }
  }
  void ex_2(int x, int y){
    if(!gol::get_cell(x,y))
      return;
    if(gol::num_of_neigbours(x,y) == 2 || gol::num_of_neigbours(x,y) == 3){
      gol::set_cell(x, y, true);
    }
  }
  void ex_3(int x, int y){
    if(!gol::get_cell(x,y))
      return;
    if(gol::num_of_neigbours(x,y) > 3){
      gol::set_cell(x, y, false);
    }
  }
  void ex_4(int x, int y){
    if(!gol::get_cell(x,y)){
      if(gol::num_of_neigbours(x,y) == 3){
        gol::set_cell(x, y, true);
      }
    }
  }
} // end internal

void init_game_of_life(std::string file_name = "gol.gif"){
  std::cout << "Intialising Game of Life \n";
  std::cout << "Output file name set to: " << file_name <<'\n';

	GifBegin(&internal::g, file_name.c_str(), GRID_X, GRID_Y, DELAY);
}

void seed_grid(std::string file_path = "start_grid.txt"){
  std::string line;
  std::ifstream grid_init_file (file_path);
  
  if (grid_init_file.is_open()){
    while ( getline (grid_init_file,line) ){
      if(!line.empty()){
        if(std::find_if(line.begin(), 
        line.end(), [](unsigned char c) { return !std::isdigit(c) && c != ' '; }) == line.end()){
          auto [x , y] = internal::parse_line(line);
          if(x < GRID_X || y < GRID_Y){
            internal::grid[x+1][y+1] = true;
          } else {
            std::cout << "Could not add cell: Coordinates out of bounds.\n";
          }
        }else{
          internal::add_preset(line);
        }
      }
    }
    grid_init_file.close();
  } else std::cout << "Unable to open file :" << file_path << '\n';

}

int num_of_neigbours(int x, int y){

  x++;
  y++;
  int counter = 0;

  if(internal::prev_grid[x-1][y-1]) counter++;
  if(internal::prev_grid[x-1][y]) counter++;
  if(internal::prev_grid[x-1][y+1]) counter++;

  if(internal::prev_grid[x][y-1]) counter++;
  if(internal::prev_grid[x][y+1]) counter++;

  if(internal::prev_grid[x+1][y-1]) counter++;
  if(internal::prev_grid[x+1][y]) counter++;
  if(internal::prev_grid[x+1][y+1]) counter++; 

  return counter;
}

void write_frame(){
  std::vector<uint8_t> image((GRID_X + 2) * (GRID_Y + 2) * 4);
  
  for (size_t i = 1; i < GRID_X + 1; i++){
    for (size_t j = 1; j < GRID_Y + 1; j++){ 
      for (size_t k = 0; k < 4; k++){

        const int one_d_map = i + GRID_X  * j;
        const int index = (one_d_map * 4) + k;
        image[index] = internal::grid[i][j] ? 255 : 0;
      }
    }
  }
	GifWriteFrame(&internal::g, image.data(), GRID_X, GRID_Y, DELAY);
  std::swap(internal::prev_grid,internal::grid);
  internal::clear_grid();
}

void render(){
  GifEnd(&internal::g);
}
const int get_x_dimension(){
  return GRID_X;
}

const int get_y_dimension(){
  return GRID_Y;
}

bool get_cell(int x, int y){
  return internal::prev_grid[x + 1][y + 1];
}

void set_cell(int x, int y, bool value){
  internal::grid[x + 1][y + 1] = value;
}

//For Debug ...
void print_grid(){
  for (size_t i = 0; i < GRID_X + 2; i++){
    for (size_t j = 0; j < GRID_Y + 2; j++){
      std::cout << std::boolalpha << internal::grid[i][j] << ' ';
    }
    std::cout << '\n';
  }
}

void print_img(std::vector<uint8_t> img){
  for (size_t i = 0; i < GRID_X*4; i++){
    for (size_t j = 0; j < GRID_Y*4; j++){
      if (img[i + (GRID_X * 4) * j] == 255)
        std::cout << 'x' << ' ';
      else
        std::cout << '0' << ' ';
    }
    std::cout << '\n';
  }
}

void run_gol(std::function<void(int,int)> r1 = internal::ex_1,
                    std::function<void(int,int)> r2 = internal::ex_2,
                    std::function<void(int,int)> r3 = internal::ex_3,
                    std::function<void(int,int)> r4 = internal::ex_4){
  gol::init_game_of_life("Experimenting.gif");
  gol::seed_grid();
  gol::write_frame();

  int num_frames = 100;
  for (size_t i = 0; i < num_frames; i++){
    for (size_t j = 0; j < gol::get_x_dimension(); j++){
      for (size_t k = 0; k < gol::get_y_dimension(); k++){
        r1(j,k);
        r2(j,k);
        r3(j,k);
        r4(j,k);
      }
    } 
    gol::write_frame();
  }
  gol::render();
}

}