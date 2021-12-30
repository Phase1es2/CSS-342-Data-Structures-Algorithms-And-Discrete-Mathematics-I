/*
 * @Author: Hao Yang
 * @Date: 2021-11-26 16:41:30
 * @LastEditTime: 2021-12-15 21:16:47
 * @LastEditors: momo.local
 * @Description: In User Settings Edit
 * @FilePath: /342/account.cpp
 */

#include "account.h"

/**
 * @description:
 * @param {string} FirstName
 * @param {string} LastName
 * @param {int} AccountID
 * @return {*}
 */
Acoount::Acoount(string FirstName, string LastName, int AccountID) {
  check_ = false;
  first_name_ = FirstName;
  last_name_ = LastName;
  account_id_ = AccountID;
  string fundType[] = {"Money Market",       "Prime Money Market",
                       "Long-Term Bond",     "Short-Term Bond",
                       "500 Index Fund",     "Capital Value Fund",
                       "Growth Equity Fund", "Growth Index Fund"};

  for (int i = 0; i < 8; i++) {
    fund_[i].setFundType(fundType[i]);
    fund_[i].setBalance(0);
  }
}

/**
 * @description:
 * @param {*}
 * @return {*}
 */
string Acoount::getFirstName() const { return first_name_; }

/**
 * @description:
 * @param {*}
 * @return {*}
 */
string Acoount::getLastName() const { return last_name_; }

/**
 * @description:
 * @param {int} FundID
 * @return {*}
 */
string Acoount::getFundtype(int FundID) const {
  return fund_[FundID].getFundType();
}

/**
 * @description:
 * @param {int} FundID
 * @return {*}
 */
int Acoount::getBalance(int FundID) const { return fund_[FundID].getBalance(); }

/**
 * @description:
 * @param {int} Amount
 * @param {int} FundID
 * @return {*}
 */
bool Acoount::addToFund(int Amount, int FundID) {
  if (Amount < 0) {
    return false;
  } else {
    fund_[FundID].Deposit(Amount);
    return true;
  }
}

/**
 * @description:
 * @param {*}
 * @return {*}
 */
bool Acoount::removeFromFund(int Amount, int FundID) {
  if (fund_[FundID].isBalanceEnough(Amount)) {
    fund_[FundID].Withdraw(Amount);
    return true;
  }
  if (FundID >= 0 && FundID <= 3) {
    if (FundID == 0) {
      if (fund_[FundID].getBalance() + fund_[1].getBalance() >= Amount) {
        int left = Amount - fund_[FundID].getBalance();
        fund_[FundID].Withdraw(Amount - left);
        fund_[1].Withdraw(left);
        Transaction* first =
            new Transaction('W', account_id_, FundID, Amount - left);
        Transaction* second = new Transaction('W', account_id_, FundID, left);
        fund_[FundID].addTransaction(*first);
        fund_[1].addTransaction(*second);
        check_ = true;
        return true;
      }
    } else if (FundID == 1) {
      if (fund_[FundID].getBalance() + fund_[0].getBalance() >= Amount) {
        int left = Amount - fund_[FundID].getBalance();
        fund_[FundID].Withdraw(Amount - left);
        fund_[0].Withdraw(left);
        Transaction* first =
            new Transaction('W', account_id_, FundID, Amount - left);
        Transaction* second = new Transaction('W', account_id_, FundID, left);
        fund_[1].addTransaction(*first);
        fund_[0].addTransaction(*second);
        check_ = true;
        return true;
      }
    } else if (FundID == 2) {
      if (fund_[FundID].getBalance() + fund_[FundID + 1].getBalance() >=
          Amount) {
        int left = Amount - fund_[FundID].getBalance();
        fund_[FundID].Withdraw(Amount - left);
        fund_[3].Withdraw(left);
        Transaction* first =
            new Transaction('W', account_id_, FundID, Amount - left);
        Transaction* second = new Transaction('W', account_id_, FundID, left);
        fund_[FundID].addTransaction(*first);
        fund_[3].addTransaction(*second);
        check_ = true;
        return true;
      }
    } else if (FundID == 3) {
      if (fund_[FundID].getBalance() + fund_[FundID - 1].getBalance() >=
          Amount) {
        int left = Amount - fund_[FundID].getBalance();
        fund_[FundID].Withdraw(Amount - left);
        fund_[2].Withdraw(left);
        Transaction* first =
            new Transaction('W', account_id_, FundID, Amount - left);
        Transaction* second = new Transaction('W', account_id_, FundID, left);
        fund_[FundID].addTransaction(*first);
        fund_[2].addTransaction(*second);
        check_ = true;
        return true;
      }
    }
  }
}

/**
 * @description:
 * @param {*}
 * @return {*}
 */
void Acoount::printAllHistory() {
  for (int i = 0; i < 8; i++) {
    fund_[i].printHistory();
  }
}

/**
 * @description:
 * @param {int} FundID
 * @return {*}
 */
void Acoount::printFundHistory(int FundID) { fund_[FundID].printHistory(); }

/**
 * @description:
 * @param {Transaction} t
 * @param {int} FundID
 * @return {*}
 */
void Acoount::addToTransaction(Transaction t, int FundID) {
  fund_[FundID].addTransaction(t);
}

/**
 * @description:
 * @param {*}
 * @return {*}
 */
bool Acoount::insertCheck() const { return check_; }

/**
 * @description:
 * @param {*}
 * @return {*}
 */
Acoount::~Acoount() {}

/**
 * @description:
 * @param {string} FirstName
 * @return {*}
 */
void Acoount::setFirstName(string FirstName) { first_name_ = FirstName; }

/**
 * @description:
 * @param {string} LastName
 * @return {*}
 */
void Acoount::setLastName(string LastName) { last_name_ = LastName; }

/**
 * @description:
 * @param {int} AccountID
 * @return {*}
 */
bool Acoount::setAccountID(int AccountID) {
  account_id_ = AccountID;
  return true;
}

/**
 * @description:
 * @param {*}
 * @return {*}
 */
int Acoount::getAccountID() const { return account_id_; }
