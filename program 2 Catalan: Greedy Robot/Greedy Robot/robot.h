#pragma once
#include <string>

#include "treasrue.h"
using namespace std;

class Robot {
 public:
  Robot(int xr, int yr, int xt, int yt, int maxd);
  ~Robot();

  int MaxDisantance();
  int ShortestPossibleDistance(int xr, int yr, int xt, int yt);
  int findPaths(int xr, int yr, int xt, int yt, int maxd, string answer);

  friend ostream& operator<<(ostream& is, Robot& rhs);

 private:
  int xr_;
  int yr_;
  int xt_;
  int yt_;
  int maxdistance_;
  int north_;
  int south_;
  int west_;
  int east_;
  Treasrue startPlace_;
  Treasrue endPlace_;
  // string direction_;
  int ShortestPossibleDistance_;

  //	int x_;
  //	int y_;

  string answer;
};
