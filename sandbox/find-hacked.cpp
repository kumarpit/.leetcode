// find the hacked server in a grid given string direction hints (eg. "U", "L",
// "DR") etc.

#include <string>
#include <utility>

// gets called in a loop
std::pair<int, int> solve(std::string direction, int x, int y, int width,
                          int height) {
  // using static to "remember" the bounding box across function call
  // invocations
  static int minX = 0, maxX = width - 1;
  static int minY = 0, maxY = height - 1;

  if (direction.find('U') != std::string::npos)
    maxY = y - 1;
  if (direction.find('D') != std::string::npos)
    minY = y + 1;
  if (direction.find('L') != std::string::npos)
    maxX = x - 1;
  if (direction.find('R') != std::string::npos)
    minX = x + 1;

  int newX = (minX + maxX) / 2;
  int newY = (minY + maxY) / 2;

  return {newX, newY};
}
