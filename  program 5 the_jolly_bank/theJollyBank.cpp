/*
 * @Author: Hao Yang
 * @Date: 2021-11-26 16:32:33
 * @LastEditTime: 2021-12-29 10:03:58
 * @LastEditors: momo.local
 * @Description: In User Settings Edit
 * @FilePath: /342/TheJollyBank.cpp
 */

#include <fstream>
#include <iostream>
#include <vector>

#include "bank.h"

using namespace std;

int main(int argc, char* argv[]) {
  Bank b;
  for (int i = 1; i < argc; i++) {
    cout << "The command Line argument was: " << argv[i] << endl;
    string file = argv[i];
    b.ReadFile(file);
    b.Process();
    b.Print();
  }
  return 0;
}
