#ifndef TIME_SPAN_H_
#define TIME_SPAN_H_
#include <iostream>
using namespace std;

class TimeSpan {
 public:
  // Constructors
  TimeSpan();
  TimeSpan(double hours, double minutes, double seconds);
  TimeSpan(double minutes, double seconds);
  TimeSpan(double seconds);

  // getters-setters
  int hours() const;
  int minutes() const;
  int seconds() const;
  void set_time(int hours, int minutes, int seconds);

  // Math Operator: addition, subtraction, unary negation
  TimeSpan operator+(const TimeSpan& rhs) const;
  TimeSpan& operator+=(const TimeSpan& rhs);
  TimeSpan operator-(const TimeSpan& rhs) const;
  TimeSpan& operator-=(const TimeSpan& rhs);
  TimeSpan operator-() const;

  // Stream I/O
  friend ostream& operator<<(ostream& stream, const TimeSpan& rhs);
  friend istream& operator>>(istream& stream, TimeSpan& rhs);

  // Comparison Operators
  bool operator==(const TimeSpan& rhs) const;
  bool operator!=(const TimeSpan& rhs) const;
  bool operator<(const TimeSpan& rhs) const;
  bool operator<=(const TimeSpan& rhs) const;
  bool operator>(const TimeSpan& rhs) const;
  bool operator>=(const TimeSpan& rhs) const;

 private:
  int hours_;
  int minutes_;
  int seconds_;
};
#endif