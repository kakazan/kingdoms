#include "view.hpp"

/******************************************************************************
 * Public
 * ***************************************************************************/
View::~View() {
  endwin();
}

WINDOW *View::getUIWindow() {
  return UIWindow;
}

WINDOW *View::getInputWindow() {
  return inputWindow;
}

void View::init() {
  initVars();
  initUIWindow();
  initInputWindow();
  refresh();
}

void View::refreshUIWindow() {
  wrefresh(UIWindow);
}

void View::refreshInputWindow() {
  wrefresh(inputWindow);
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
  initscr();
  clear();
  keypad(stdscr, TRUE); // TODO: get function keys F1, F2 etc.
  noecho();             // TODO: do I need this?
  getmaxyx(stdscr, LINES, COLUMNS);
}

void View::initUIWindow() {
  UIWindow = newwin(LINES-inputWindowSize,    // nlines
                    COLUMNS-1,                // ncols
                    0,                        // y0
                    0);                       // x0
  box(UIWindow, 0, 0);
}

void View::initInputWindow() {
  inputWindow = newwin(inputWindowSize,            // nlines
                       COLUMNS-1,                // ncols
                       LINES-inputWindowSize,      // y0
                       0);                       // x0
  box(inputWindow, 0, 0);
}
