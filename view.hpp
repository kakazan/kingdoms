#ifndef __VIEW_HPP__
#define __VIEW_HPP__

#include <ncurses.h>
#include "window.hpp"

class View {
    static const int inputWindowSize = 3;

    int LINES;
    int COLUMNS;

    Window *inputWindow;
    Window *UIWindow;

  public:
    ~View() {
      delete inputWindow;
      delete UIWindow;
      endwin();
    };

    void init();
    void refreshUIWindow();
    void refreshInputWindow();
    void refresh();

  private:
    void initVars();
    void initWindows();
};

#endif
