/*
 * @Author: Hao Yang
 * @Date: 2021-11-26 16:32:45
 * @LastEditTime: 2021-12-15 19:15:49
 * @LastEditors: momo.local
 * @Description: In User Settings Edit
 * @FilePath: /342/bank.cpp
 */

#include "bank.h"

/**
 * @description:
 * @param {*}
 * @return {*}
 */
Bank::Bank() {}

/**
 * @description:
 * @param {*}
 * @return {*}
 */
Bank::~Bank() {}

/**
 * @description:
 * @param {string} file
 * @return {*}
 */
void Bank::ReadFile(string file) {
  ifstream infile(file);
  string line;
  while (getline(infile, line)) {
    istringstream theLine(line);
    char type;
    theLine >> type;
    if (type == 'O') {
      string LastName;
      string FirstName;
      int AccountID;
      theLine >> AccountID >> LastName >> FirstName;
      Transaction tmp(type, AccountID, LastName, FirstName);
      q_.push(tmp);
    } else if (type == 'D' || type == 'W') {
      int AccountID;
      int FundID;
      int amount;
      theLine >> AccountID >> FundID >> amount;
      Transaction tmp(type, AccountID, FundID, amount);
      q_.push(tmp);
    } else if (type == 'T') {
      int AccountID;
      int FundID;
      int AccountID2;
      int FundID2;
      int amount;
      theLine >> AccountID >> FundID >> AccountID2 >> FundID2 >> amount;
      Transaction tmp(type, AccountID, FundID, AccountID2, FundID2, amount);
      q_.push(tmp);
    } else if (type == 'A') {
      int AccountID;
      theLine >> AccountID;
      Transaction tmp(type, AccountID);
      q_.push(tmp);
    } else if (type == 'F') {
      int AccountID, FundID;
      theLine >> AccountID >> FundID;
      Transaction tmp(type, AccountID, FundID);
      q_.push(tmp);
    } else {
      cout << "Transaction Code not found!" << endl;
    }
  }
}

void Bank::Process() {
  while (!q_.empty()) {
    Transaction tmp = q_.front();
    if (tmp.getType() == 'O') {
      Acoount* acc = new Acoount(tmp.getFirstName(), tmp.getLastName(),
                                 tmp.getAccountID());
      if (!a_.Insert(acc)) {
        cerr << "ERROR: Account: " << tmp.getAccountID()
             << " is already open. Transferal refused." << endl;
      }
      if (acc->getAccountID() < 0) {
        cerr << "ERROR: " << acc->getAccountID()
             << " is an invalid account ID. Transaction refused." << endl;
      }
    } else if (tmp.getType() == 'D') {
      int FundID = tmp.getFundID();
      int AccountID = tmp.getAccountID();
      int amount = tmp.getAmount();
      Acoount* acc;
      if (a_.Retrieve(AccountID, acc)) {
      }
      if (acc->addToFund(amount, FundID)) {
        tmp.setTransactiontatment(true);
      } else {
        tmp.setTransactiontatment(false);
        cerr << "ERROR: Deposit amount " << tmp.getAmount()
             << " is not allowed. Transaction refused" << endl;
      }
      if (!acc->insertCheck()) {
        acc->addToTransaction(tmp, FundID);
      }
    } else if (tmp.getType() == 'W') {
      int FundID = tmp.getFundID();
      int AccountID = tmp.getAccountID();
      int amount = tmp.getAmount();
      Acoount* acc;
      if (a_.Retrieve(AccountID, acc)) {
      }
      if (acc->removeFromFund(amount, FundID)) {
        tmp.setTransactiontatment(true);
      } else {
        tmp.setTransactiontatment(false);
        cerr << "ERROR: Not enough funds to withdraw " << tmp.getAmount()
             << " from" << tmp.getFirstName() << " " << tmp.getLastName() << " "
             << acc->getFirstName() << " " << acc->getLastName() << " "
             << acc->getFundtype(FundID) << endl;
      }
      if (!acc->insertCheck()) {
        acc->addToTransaction(tmp, FundID);
      }
    } else if (tmp.getType() == 'T') {
      int fromFundID = tmp.getFundID();
      int fromAccID = tmp.getAccountID();
      int toFundID = tmp.getFundID2();
      int toAccID = tmp.getAccountID2();
      int amount = tmp.getAmount();

      Acoount *from, *to;
      a_.Retrieve(fromAccID, from);
      a_.Retrieve(toAccID, to);
      if (a_.Retrieve(fromAccID, from)) {
        if (a_.Retrieve(toAccID, to)) {
          if (from->removeFromFund(amount, fromFundID)) {
            to->addToFund(amount, toFundID);
            to->addToTransaction(tmp, toFundID);
            from->addToTransaction(tmp, fromFundID);
          } else {
            cerr << "ERROR: Unsufficent Funds to conduct transfer. From "
                    "account number: "
                 << from->getAccountID()
                 << " account: " << from->getFundtype(fromFundID)
                 << " to account number: " << to->getAccountID()
                 << " account: " << to->getFundtype(toFundID)
                 << " from the amount of: " << tmp.getAmount() << endl;
          }
        } else {
          cerr << "ERROR: Account: " << toAccID
               << " not found. Transferal refused" << endl;
        }

      } else {
        cerr << "ERROR: Account: " << fromAccID
             << " not found. Transferal refused" << endl;
      }
    } else if (tmp.getType() == 'A') {
      if (tmp.getAccountID() >= 0) {
        Acoount* acc;
        if (a_.Retrieve(tmp.getAccountID(), acc)) {
          cout << "Transaction History for " << acc->getFirstName() << " "
               << acc->getLastName() << " by fund." << endl;
          acc->printAllHistory();
        } else {
          cerr << "ERROR: Account " << tmp.getAccountID() << " not found."
               << endl;
        }
      }
    } else if (tmp.getType() == 'F') {
      if (tmp.getAccountID() >= 0) {
        int FundID = tmp.getFundID();
        int AccountID = tmp.getAccountID();
        Acoount* acc;
        if (a_.Retrieve(AccountID, acc)) {
          cout << "Transaction History for " << acc->getFirstName() << " "
               << acc->getLastName() << " ";
          acc->printFundHistory(FundID);
          cout << endl;
        } else {
          cerr << "ERROR: Account " << AccountID << " not found." << endl;
        }
      }
    }
    q_.pop();
  }
  /**
   * @description:
   * @param {*}
   * @return {*}
   */
}

/**
 * @description:
 * @param {*}
 * @return {*}
 */
void Bank::Print() {
  cout << "FINAL BALANCES:" << endl;
  a_.Display();
}
