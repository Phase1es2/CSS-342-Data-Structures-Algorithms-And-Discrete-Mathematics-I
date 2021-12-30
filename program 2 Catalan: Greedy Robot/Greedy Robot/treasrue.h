#pragma once
class Treasrue {
 public:
  Treasrue();
  Treasrue(int xt, int yt);
  ~Treasrue();

  int getX() const;
  int getY() const;

 private:
  int xt_;
  int yt_;
};
