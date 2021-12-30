/*
 * @Author: Hao Yang
 * @Date: 2021-11-26 16:34:29
 * @LastEditTime: 2021-12-15 21:27:05
 * @LastEditors: momo.local
 * @Description: In User Settings Edit
 * @FilePath: /342/funds.cpp
 */
#include "fund.h"

/**
 * @description:
 * @param {*}
 * @return {*}
 */
Fund::Fund() { balance_ = 0; }

/**
 * @description:
 * @param {string} fundType
 * @return {*}
 */
Fund::Fund(string fundType) {
  type_ = fundType;
  balance_ = 0;
}

/**
 * @description:
 * @param {*}
 * @return {*}
 */
Fund::~Fund() {}

/**
 * @description:
 * @param {*}
 * @return {*}
 */
string Fund::getFundType() const { return type_; }

/**
 * @description:
 * @param {*}
 * @return {*}
 */
int Fund::getBalance() const { return balance_; }

/**
 * @description:
 * @param {int} Amount
 * @return {*}
 */
bool Fund::Deposit(int Amount) {
  if (Amount >= 0) {
    balance_ += Amount;
    return true;
  }
  return false;
}

/**
 * @description:
 * @param {int} Amount
 * @return {*}
 */
bool Fund::Withdraw(int Amount) {
  if (isBalanceEnough(Amount)) {
    balance_ -= Amount;
  }
  return true;
}

/**
 * @description:
 * @param {Transaction} t
 * @return {*}
 */
bool Fund::addTransaction(Transaction t) {
  history_.push_back(t);
  return true;
}

/**
 * @description:
 * @param {*}
 * @return {*}
 */
void Fund::printHistory() const {
  if (history_.size() > 0) {
    cout << type_ << ": $" << balance_ << endl;
    for (unsigned long int i = 0; i < history_.size(); i++) {
      cout << " " << history_[i];
    }
  }
}
/**
 * @description:
 * @param {int} Amount
 * @return {*}
 */
bool Fund::setBalance(int Amount) {
  balance_ = Amount;
  return true;
}

/**
 * @description:
 * @param {string} fundType
 * @return {*}
 */
bool Fund::setFundType(string fundType) {
  type_ = fundType;
  return true;
}

/**
 * @description:
 * @param {int} Amount
 * @return {*}
 */
bool Fund::isBalanceEnough(int Amount) const {
  if (balance_ >= Amount) {
    return true;
  }
  return false;
}

/**
 * @description:
 * @param {*}
 * @return {*}
 */
Fund Fund::operator=(const Fund& f) {
  Fund lhs;
  lhs.history_ = f.history_;
  lhs.type_ = f.type_;
  lhs.balance_ = f.balance_;
  return lhs;
}
