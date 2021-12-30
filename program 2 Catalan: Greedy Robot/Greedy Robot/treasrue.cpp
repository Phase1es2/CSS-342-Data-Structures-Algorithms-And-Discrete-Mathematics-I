#include "treasrue.h"

Treasrue::Treasrue() : xt_(0), yt_(0) {}

Treasrue::Treasrue(int xt, int yt) {
  xt_ = xt;
  yt_ = yt;
}

Treasrue::~Treasrue() {}

int Treasrue::getX() const { return xt_; }

int Treasrue::getY() const { return yt_; }
