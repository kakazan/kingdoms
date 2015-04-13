#ifndef __ACTOR_HPP__
#define __ACTOR_HPP__

class Actor {
    int representation;
    int max_x;
    int max_y;
    int x;
    int y;

  public:
    bool active = true;

    Actor(int repr, int max_x, int max_y, int x, int y)
        : representation(repr),
          max_x(max_x),
          max_y(max_y),
          x,
          y  {};
};
#endif
