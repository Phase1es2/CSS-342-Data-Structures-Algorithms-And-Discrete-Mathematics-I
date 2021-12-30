// Catalan.cpp : This file contains the 'main' function. Program execution
// begins and ends there.
//

#include <stdlib.h>

#include <iostream>
#include <string>
using namespace std;

int Catalan(int n);

int main(int argc, char* argv[]) {
  if (argc != 2) {
    cout << "Error: Invalid number of arguments." << endl;
  }
  int input = atoi(argv[1]);

  if (input >= 0) {
    cout << "The Catalan Number of" << input << "is" << Catalan(input) << "."
         << endl;
  } else {
    cout << "Error: Catalna number cannnot be less than zero." << endl;
  }
}

int Catalan(int n) {
  if (n <= 1) return 1;

  int res = 0;
  for (int i = 0; i < n; i++) res += Catalan(i) * Catalan(n - i - 1);
  return res;
}
