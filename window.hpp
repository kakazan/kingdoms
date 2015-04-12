#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

#include <ncurses.h>

class Window {
    int x0;
    int y0;
    int LINES;
    int COLUMNS;

    WINDOW *window;

  public:
    Window(int nlines, int ncols, int x0, int y0)
        : x0(x0), y0(y0), LINES(nlines), COLUMNS(ncols) {};
    Window(const Window& other) {
      LINES = other.LINES;
      COLUMNS = other.COLUMNS;
      x0 = other.x0;
      y0 = other.y0;
      window = other.window;
    }
    Window& operator=(const Window& other) {
      LINES = other.LINES;
      COLUMNS = other.COLUMNS;
      x0 = other.x0;
      y0 = other.y0;
      window = other.window;
      return *this;
    }
    ~Window() { delwin(window); };

    void init();
    void refresh();
};

#endif
