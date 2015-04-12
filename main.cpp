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

View::~View() {
  endwin();
}

void View::init() {
  initVars();
  initUIWindow();
  initInputWindow();
  refresh();
}

WINDOW *View::getInputWindow() {
  return inputWindow;
}

WINDOW *View::getUIWindow() {
  return UIWindow;
}

int main(int argc, char* argv[]) {
  View view;

  view.init();
  
  while(true) {
  }

  return 0;
}
