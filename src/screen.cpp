//Library Directives
#include <random>
#include <curses.h>

//Project Directives
#include "../headers/screen.hpp"

//Constructor
Screen::Screen(int h, int w, int y, int x){
  this->win = newwin(h,w,y,x);
  this->h = h;
  this->w = w;
  this->y = y;
  this->x = x;
}

void Screen::fill(const char* c, int col){
  wattron(this->win, COLOR_PAIR(col));
  
  for(int i = 0; i < this->h; i++)
    mvwhline(this->win, i, 0, *c, this->w);
  
  wattroff(this->win, COLOR_PAIR(col));
}

void Screen::fill_randomly(int seed, const char* c, int col, int chance){
  std::default_random_engine rand(seed);
  std::uniform_int_distribution<int> roll(0,100);

  wattron(this->win, COLOR_PAIR(col));
  
  for(int i = 0; i < this->h; i++)
    for(int j = 0; j < this->w; j++)
      if(roll(rand) < chance)
        mvwprintw(this->win, i, j, c);
  
  wattroff(this->win, COLOR_PAIR(col));
}

void Screen::cross(const char* c, int col, int y, int x){
  wattron(this->win, COLOR_PAIR(col));
  
  mvwhline(this->win, y, 0, *c, this->w);
  mvwvline(this->win, 0, x*2, *c, this->h);
  mvwvline(this->win, 0, x*2+1, *c, this->h);
  
  wattroff(this->win, COLOR_PAIR(col));
}

void Screen::grid(const char* c, int col, int spacing, int y_offset, int x_offset){
  for(int i = 0; i < std::max(this->h, this->w); i += spacing+1)
    cross(c, col, i+y_offset, i+x_offset);
}

void Screen::dotted_v_line(const char* c, int col, int y, int spacing){
  wattron(this->win, COLOR_PAIR(col));
  
  for(int i = 0; i < this->w; i += spacing*4)
    mvwhline(this->win, y, i, *c, spacing*2);
  
  wattroff(this->win, COLOR_PAIR(col));
}

void Screen::dotted_h_line(const char* c, int col, int x, int spacing){
  wattron(this->win, COLOR_PAIR(col));
  
  for(int i = 0; i < this->w; i += spacing*2){
    mvwvline(this->win, i, x+x , *c, spacing);
    mvwvline(this->win, i, x+x+1, *c, spacing);
  }
  
  wattroff(this->win, COLOR_PAIR(col));
}

void Screen::polka_dot(const char* c, int col, int spacing){
  wattron(this->win, COLOR_PAIR(col));
  
  for(int i = 0; i < this->w; i += spacing*4)
    for(int j = 0; j < spacing*2; j++)
      for(int k = 0; k < this->h; k+=spacing*2)
        mvwvline(this->win, k, j+i, *c, spacing);
  
  wattroff(this->win, COLOR_PAIR(col));
}

void Screen::checker(const char* c, int col, int spacing){
  wattron(this->win, COLOR_PAIR(col));
  
  for(int i = 0; i < this->w; i+=spacing*4)
    for(int j = 0; j < spacing*2; j++)
      for(int k = 0; k < this->h; k += spacing * 2){
        mvwvline(this->win, k, j+i, *c, spacing);
        mvwvline(this->win, k+spacing, j+i+spacing*2, *c, spacing);
      }
  
  wattroff(this->win, COLOR_PAIR(col));
}
