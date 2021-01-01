//Library Directives
#include <curses.h>
#include <memory>

//Project Directives
#include "headers/screen.hpp"

//Main Function
int main(int argc, char** argv){
  initscr();
  cbreak();
  raw();
  noecho();
  start_color();

  //Initialise colours
  init_pair(1,9,0); //FG: red, BG: black
  init_pair(2,12,0); //FG: blue, BG: black
  init_pair(3,9,9); //FG: red, BG: red
  init_pair(4,12,12); //FG: blue, BG: blue

  //Create screens
  std::unique_ptr<Screen> s = std::make_unique<Screen>(31,62,0,0);
  std::unique_ptr<Screen> s2 = std::make_unique<Screen>(31,62,0,64);
  refresh();

  s->fill(".", 1);
  s->grid("X", 2, 2);
  wrefresh(s->win);

  s2->fill(".", 3);
  s2->grid("X", 4, 2);
  wrefresh(s2->win);
  
  refresh();
  getch();
  endwin();
}
