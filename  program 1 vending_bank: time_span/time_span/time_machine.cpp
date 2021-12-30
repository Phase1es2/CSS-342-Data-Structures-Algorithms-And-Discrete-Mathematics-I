// time_machine.cpp : This file contains the 'main' function. Program execution
// begins and ends there.
//

#include <iostream>

#include "time_span.h"
using namespace std;

int main() {
  TimeSpan dur1(77.4, 15, 6), dur2(127.86), dur3(8, -23, 0), dur4(0, 0, 0);
  TimeSpan dur5(-3, 73, 2), dur6(7, 35, 120), dur7, dur8;
  TimeSpan dur9(1, -71, 1), dur10(0, -61, 2), dur11(-1.3, 13);
  TimeSpan dur12(1, 30, 1), dur13(2, -30, 1), dur14;

  dur7 = dur1 + dur3;

  cout << dur1 << endl;
  cout << dur2 << endl;
  cout << dur3 << endl;
  cout << dur4 << endl;
  cout << dur5 << endl;
  cout << dur6 << endl;
  cout << dur7 << endl;
  cout << dur8 << endl;
  cout << dur9 << endl;
  cout << dur10 << endl;
  cout << dur11 << endl;
  cout << dur12 << endl;
  cout << dur13 << endl;

  dur7 += dur3;
  cout << dur3 << endl;
  cout << dur7 << endl;

  if (dur3 != dur6) {
    cout << "Durations are different." << endl;

  } else {
    cout << "Duration are the same." << endl;
  }

  if (dur12 == dur13) {
    cout << "Duration are the same." << endl;
  } else {
    cout << "Duration are diferent." << endl;
  }

  dur14 = -dur1;

  cout << dur14 << endl;

  if (dur1 <= dur2) {
    cout << "The frist duration is longer or same as the seconds duration."
         << endl;
  } else {
    cout << "the seconds duration is longer." << endl;
  }
}
