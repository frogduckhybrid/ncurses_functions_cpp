#pragma once

//Library Directives
#include <curses.h>

//Project Directives

//Class Definition
class Screen {
  int h;
  int w;
  int y;
  int x;

public:

  WINDOW *win;
  Screen(int h, int w, int y, int x);

  //Methods
  void fill(const char* c, int col);
  void fill_randomly(int seed, const char* c, int col, int percent);
  void cross(const char* c, int col, int x, int y);
  void grid(const char* c, int col, int spacing, int x_offset = 0, int y_offset = 0);
  void dotted_v_line(const char* c, int col, int y, int spacing);
  void dotted_h_line(const char* c, int col, int x, int spacing);
  void polka_dot(const char* c, int col, int spacing);
  void checker(const char* c , int col, int spacing);
};
