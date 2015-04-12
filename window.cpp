#include "window.hpp"

void Window::init() {
  window = newwin(LINES,
                  COLUMNS,
                  y0,                        // y0
                  x0);                       // x0
  box(window, 0, 0);
}

void Window::refresh() {
  wrefresh(window);
}
