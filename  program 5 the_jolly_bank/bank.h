/*
 * @Author: Hao Yang
 * @Date: 2021-11-26 16:32:40
 * @LastEditTime: 2021-12-15 21:27:48
 * @LastEditors: momo.local
 * @Description: In User Settings Edit
 * @FilePath: /342/bank.h
 */
#ifndef BANK_H_
#define BANK_H_
#include <fstream>
#include <iostream>
#include <queue>
#include <sstream>
#include <vector>

#include "bstree.h"
#include "transaction.h"
using namespace std;
class Bank {
 public:
  Bank();
  ~Bank();
  void ReadFile(string file);
  void Process();
  void Print();

 private:
  BSTree a_;

  queue<Transaction> q_;
};

#endif
