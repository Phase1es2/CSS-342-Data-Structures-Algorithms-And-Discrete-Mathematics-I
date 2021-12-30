// greedy_robot_.cpp : This file contains the 'main' function. Program execution
// begins and ends there.
//
#include <iostream>

#include "robot.h"
#include "treasrue.h"
using namespace std;

int main(int argc, char* argv[]) {
  if (argc != 6) {
    cout << "Enter 5 number please." << endl;
  }

  int input1 = atoi(argv[1]);
  int input2 = atoi(argv[2]);
  int input3 = atoi(argv[3]);
  int input4 = atoi(argv[4]);
  int input5 = atoi(argv[5]);

  Robot is(input1, input2, input3, input4, input5);

  // Robot is(1, 2, 3, 5, 2);
  cout << is << endl;
}
