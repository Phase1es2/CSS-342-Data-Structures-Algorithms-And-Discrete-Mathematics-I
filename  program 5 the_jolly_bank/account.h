/*
 * @Author: Hao Yang
 * @Date: 2021-11-26 16:41:25
 * @LastEditTime: 2021-12-15 13:14:17
 * @LastEditors: momo.local
 * @Description: In User Settings Edit
 * @FilePath: /342/account.h
 */

#ifndef ACOOUNT_H_
#define ACOOUNT_H_
#include <iostream>
#include <vector>

#include "fund.h"
#include "transaction.h"
using namespace std;

class Acoount {
 public:
  Acoount(string FirstName, string LastName, int AccountID);
  ~Acoount();

  string getFirstName() const;
  string getLastName() const;
  string getFundtype(int FundID) const;
  int getBalance(int FundID) const;
  int getAccountID() const;

  bool addToFund(int Amount, int FundID);
  bool removeFromFund(int Amount, int FundID);

  void printAllHistory();
  void printFundHistory(int FundID);
  void addToTransaction(Transaction t, int FundID);
  bool insertCheck() const;
  void setFirstName(string FirstName);
  void setLastName(string LastName);
  bool setAccountID(int AccountID);

 private:
  string first_name_;
  string last_name_;
  int account_id_;

  Fund fund_[8];
  bool check_;
};

#endif
