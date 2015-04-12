#ifndef __VIEW_HPP__
#define __VIEW_HPP__

#include <ncurses.h>

class View {
    static const int inputWindowSize = 3;

    int LINES;
    int COLUMNS;

    WINDOW *inputWindow = NULL;
    WINDOW *UIWindow = NULL;

  public:
    ~View();
    WINDOW *getUIWindow();
    WINDOW *getInputWindow();
    void init();
    void refreshUIWindow();
    void refreshInputWindow();
    void refresh();

  private:
    void initVars();
    void initUIWindow();
    void initInputWindow();
};

#endif
