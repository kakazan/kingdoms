#include "view.hpp"

/******************************************************************************
 * Public
 * ***************************************************************************/
void View::init() {
  initVars();
  initWindows();
  refresh();
}

void View::refreshUIWindow() {
  UIWindow->refresh();
}

void View::refreshInputWindow() {
  inputWindow->refresh();
}

void View::refresh() {
  refreshUIWindow();
  refreshInputWindow();
}

/******************************************************************************
 * Private
 * ***************************************************************************/
void View::initVars() {
  initscr();
  clear();
  keypad(stdscr, TRUE); // TODO: get function keys F1, F2 etc.
  noecho();             // TODO: do I need this?
  getmaxyx(stdscr, LINES, COLUMNS);
}

void View::initWindows() {
  UIWindow = new Window(LINES-inputWindowSize,
                        COLUMNS-1,
                        0,
                        0);
  inputWindow = new Window(inputWindowSize,
                           COLUMNS-1,
                           0,
                           LINES-inputWindowSize);
  UIWindow->init();
  inputWindow->init();
}
