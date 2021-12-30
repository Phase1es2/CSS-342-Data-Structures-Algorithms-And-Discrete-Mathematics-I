#include "robot.h"
//#include "treasrue.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

static vector<string> paths_;

Robot::Robot(int xr, int yr, int xt, int yt, int maxd) {
  xr_ = xr;
  yr_ = yr;
  xt_ = xt;
  yt_ = yt;
  maxdistance_ = maxd;

  if (xr == xt && yr == yt) {
    ShortestPossibleDistance_ = 0;
    // direction_ = "";
    cout << "The robot and treasure are at same place!" << endl;
    cout << "You find the treasure!" << endl;
  } else {
    // findPaths(xr, yr, xt, yt, maxd, "");
    north_ = maxdistance_;
    east_ = maxdistance_;
    west_ = maxdistance_;
    south_ = maxdistance_;
    findPaths(xr, yr, xt, yt, maxd, "");
  }
}

Robot::~Robot() {}

int Robot::MaxDisantance() { return maxdistance_; }

int Robot::ShortestPossibleDistance(int xr, int yr, int xt, int yt) {
  return abs(xr - xt) + abs(yr - yt);
}

int Robot::findPaths(int xr, int yr, int xt, int yt, int maxd, string answer)
// int Robot::findPaths(int xr, int yr, int xt, int yt, int maxd, string answer)
{
  if ((xr == xt) && (yr == yt)) {
    paths_.push_back(answer);
    return 1;
  }

  int ans = 0;

  if ((yr < yt) && (north_ != 0)) {
    north_--;
    east_ = maxdistance_;
    west_ = maxdistance_;
    south_ = maxdistance_;

    ans += findPaths(xr, yr + 1, xt, yt, maxd, answer + "N");
  }

  if ((yr > yt) && (south_ != 0)) {
    south_--;
    north_ = maxdistance_;
    west_ = maxdistance_;
    east_ = maxdistance_;

    ans += findPaths(xr, yr - 1, xt, yt, maxd, answer + "S");
  }

  if ((xr < xt) && (east_ != 0)) {
    east_--;
    north_ = maxdistance_;
    west_ = maxdistance_;
    south_ = maxdistance_;

    ans += findPaths(xr + 1, yr, xt, yt, maxd, answer + "E");
  }

  if ((xr > xt) && (west_ != 0)) {
    west_--;
    north_ = maxdistance_;
    east_ = maxdistance_;
    south_ = maxdistance_;

    ans += findPaths(xr - 1, yr, xt, yt, maxd, answer + "W");
  }
  return ans;
}

ostream& operator<<(ostream& is, Robot& rhs) {
  for (string rhs : paths_) {
    cout << rhs << endl;
  }
  is << paths_.size() << endl;
  return is;
  // TODO: insert return statement here
}
