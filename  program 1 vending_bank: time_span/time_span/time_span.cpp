#include "time_span.h"
#include <tgmath.h> 
using namespace std;

TimeSpan::TimeSpan() : hours_(0), minutes_(0), seconds_(0) {}

// set the TimeSpan when it has 3 input
TimeSpan::TimeSpan(double hours, double minutes, double seconds)
    : hours_(hours), minutes_(minutes), seconds_(seconds) {
  // convert the hours, minutes seconds to seconds.
  int time_s;
  time_s = round(hours * 3600 + minutes * 60 +
                 seconds);  // round the total seconds 0.6-->1
  hours_ = time_s / 3600;
  minutes_ = (time_s / 60) % 60;
  seconds_ = time_s % 60;
}

// set the TimeSpan when it has 2 input
TimeSpan::TimeSpan(double minutes, double seconds)
    : minutes_(minutes), seconds_(seconds) {
  // convert the hours, minutes seconds to seconds.
  int time_s;
  time_s = round(minutes * 60 + seconds);  // round the total seconds 0.6-->1
  hours_ = time_s / 3600;
  minutes_ = time_s / 60;
  seconds_ = time_s % 60;
}

// set the TimeSpan when it has 1 input
TimeSpan::TimeSpan(double seconds) : seconds_(seconds) {
  // convert the hours, minutes seconds to seconds.
  int time_s;
  time_s = round(seconds);  // round the total seconds 0.6-->1

  hours_ = time_s / 3600;
  minutes_ = (time_s % 3600) / 60;
  seconds_ = time_s % 60;
}

int TimeSpan::hours() const { return hours_; }

int TimeSpan::minutes() const { return minutes_; }

int TimeSpan::seconds() const { return seconds_; }

void TimeSpan::set_time(int hours, int minutes, int seconds) {}

TimeSpan TimeSpan::operator+(const TimeSpan& rhs) const {
  TimeSpan dur = *this;
  dur += rhs;
  return dur;
}

TimeSpan& TimeSpan::operator+=(const TimeSpan& rhs) {
  int hours = hours_ + rhs.hours();
  int minutes = minutes_ + rhs.minutes();
  int seconds = seconds_ + rhs.seconds();

  this->hours_ = hours_ + rhs.hours();
  this->minutes_ = minutes_ + rhs.minutes();
  this->seconds_ = seconds_ + rhs.seconds();

  // convert the hours, minutes seconds to seconds.
  int time_s;
  time_s = round(hours * 3600 + minutes * 60 +
                 seconds);  // round the total seconds 0.6-->1
  hours_ = time_s / 3600;
  minutes_ = (time_s / 60) % 60;
  seconds_ = time_s % 60;
  set_time(hours, minutes, seconds);
  return *this;
}

TimeSpan TimeSpan::operator-(const TimeSpan& rhs) const {
  TimeSpan time = *this;
  time -= rhs;
  return time;
}

TimeSpan& TimeSpan::operator-=(const TimeSpan& rhs) {
  int hours = hours_ - rhs.hours();
  int minutes = minutes_ - rhs.minutes();
  int seconds = seconds_ - rhs.seconds();

  this->hours_ = hours_ - rhs.hours();
  this->minutes_ = minutes_ - rhs.minutes();
  this->seconds_ = seconds_ - rhs.seconds();

  // convert the hours, minutes seconds to seconds.
  int time_s;
  time_s = round(hours * 3600 + minutes * 60 +
                 seconds);  // round the total seconds 0.6-->1
  hours_ = time_s / 3600;
  minutes_ = (time_s / 60) % 60;

  seconds_ = time_s % 60;
  set_time(hours, minutes, seconds);
  return *this;
}

bool TimeSpan::operator==(const TimeSpan& rhs) const {
  int time_s;
  time_s = round(hours_ * 3600 + minutes_ * 60 + seconds_);
  int temp_time_s;
  temp_time_s = round(rhs.hours_ * 3600 + rhs.minutes_ * 60 + rhs.seconds_);
  return (time_s == temp_time_s);
}

bool TimeSpan::operator!=(const TimeSpan& rhs) const { return !(*this == rhs); }

bool TimeSpan::operator<(const TimeSpan& rhs) const {
  int time_s;
  time_s = round(hours_ * 3600 + minutes_ * 60 + seconds_);
  int temp_time_s;
  temp_time_s = round(rhs.hours_ * 3600 + rhs.minutes_ * 60 + rhs.seconds_);
  return (time_s < temp_time_s);
}

bool TimeSpan::operator<=(const TimeSpan& rhs) const {
  int time_s;
  time_s = round(hours_ * 3600 + minutes_ * 60 + seconds_);
  int temp_time_s;
  temp_time_s = round(rhs.hours_ * 3600 + rhs.minutes_ * 60 + rhs.seconds_);
  return (time_s <= temp_time_s);
}

bool TimeSpan::operator>(const TimeSpan& rhs) const {
  int time_s;
  time_s = round(hours_ * 3600 + minutes_ * 60 + seconds_);
  int temp_time_s;
  temp_time_s = round(rhs.hours_ * 3600 + rhs.minutes_ * 60 + rhs.seconds_);
  return (time_s > temp_time_s);
}

bool TimeSpan::operator>=(const TimeSpan& rhs) const {
  int time_s;
  time_s = round(hours_ * 3600 + minutes_ * 60 + seconds_);
  int temp_time_s;
  temp_time_s = round(rhs.hours_ * 3600 + rhs.minutes_ * 60 + rhs.seconds_);
  return (time_s >= temp_time_s);
}

// Unary Negation operator
TimeSpan TimeSpan::operator-() const {
  TimeSpan tmp;
  tmp.hours_ = -hours_;
  tmp.minutes_ = -minutes_;
  tmp.seconds_ = -seconds_;
  return tmp;
}

// Operator that set out put as "Hours: 1, Minutes: 2, Seconds: 3"
ostream& operator<<(ostream& stream, const TimeSpan& rhs) {
  stream << "Hours: " << rhs.hours() << ","
         << "Mintues: " << rhs.minutes() << ", "
         << "Seconds: " << rhs.seconds() << endl;
  return stream;
}

// Opeaotr the allow user to make thir own TimeSpan
istream& operator>>(istream& stream, TimeSpan& rhs) {
  stream >> rhs.hours_;
  stream >> rhs.minutes_;
  stream >> rhs.seconds_;
  int temp_hours = rhs.hours_;
  int temp_minutes = rhs.minutes_;
  int temp_seconds = rhs.seconds_;

  // convert the hours, minutes seconds to seconds.
  int time_s;
  time_s = round(temp_hours * 3600 + temp_minutes * 60 +
                 temp_seconds);  // round the total seconds 0.6-->1
  rhs.hours_ = time_s / 3600;
  rhs.minutes_ = (time_s / 60) % 60;
  rhs.seconds_ = time_s % 60;

  return stream;
}
