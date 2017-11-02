#include <iostream>
using namespace std;

// The named constructor idiom uses a set of static member functions 
// with meaningful names to create objects instead of constructors

class Game {
public:
  static Game createSinglePlayerGame() { return Game(0); } // named constructor
  static Game createMultiPlayerGame()  { return Game(1); } // named constructor

protected:
// or private:
  Game (int game_type)  { }
};

int main1(void) {
   Game g1 = Game::createSinglePlayerGame(); // Using named constructor
//   Game g2 = Game(1); // multiplayer game; without named constructor (does not compile)
  return 0;
}

#include <cmath>
class Point {
public:
  static Point Polar(float x, float y) {
    return Point(x * cos(y), x* sin(y));
  }

  static Point Rectangular(float x, float y) {
    return Point(x, y);
  }

private:
  float x1, y1;
  Point(float x, float y) : x1(x), y1(y) {}
};

int main() {
  Point pp = Point::Polar(5.7, 1.2);
  Point pr = Point::Rectangular(5.7, 1.2);

  return 0;
}
