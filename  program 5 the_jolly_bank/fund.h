/*
 * @Author: Hao Yang
 * @Date: 2021-11-26 16:34:22
 * @LastEditTime: 2021-12-15 21:26:09
 * @LastEditors: momo.local
 * @Description: In User Settings Edit
 * @FilePath: /342/funds.h
 */

#ifndef FUND_H_
#define FUND_H_
#include <vector>

#include "transaction.h"
using namespace std;

class Fund {
 public:
  Fund();
  Fund(string FundType);
  ~Fund();

  string getFundType() const;
  bool setFundType(string FundType);

  int getBalance() const;
  bool setBalance(int Amount);

  bool Deposit(int Amount);
  bool Withdraw(int Amount);

  bool addTransaction(Transaction t);

  void printHistory() const;

  bool isBalanceEnough(int Amount) const;

  Fund operator=(const Fund& f);

 private:
  string type_;
  int balance_ = 0;
  vector<Transaction> history_;
};

#endif
