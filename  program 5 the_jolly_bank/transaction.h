
#ifndef TRANSACTION_H_
#define TRANSACTION_H_
#include <iostream>
#include <string>
using namespace std;

class Transaction
{
    friend ostream& operator<<(ostream& out, const Transaction& t);
public:

    Transaction(char type, int AccountID, int FundID, int Amount);
    Transaction(char type, int AccountID, int FundID, int AccountID2, int FundID2, int Amount);
    Transaction(char type, int AccountID);
    Transaction(char type, int AccountID, int FundID);
    Transaction(char type, int AccountID, string LastName, string FirstName);


    char getType() const;
    int getAmount() const;
    bool getTransactiontatment() const;
    
    //get the element for the Account
    int getAccountID() const;
    int getFundID() const;
    string getFirstName() const;
    string getLastName() const;

 
    //get the element for the target Account
    int getAccountID2() const;
    int getFundID2() const;



   bool setTransactiontatment(bool Statment);
 


private:
    int amount_;
    char type_;
    bool s_ = false;
    //private element for the account 
    int account_id_;
    int fund_id_;
    string first_name_;
    string last_name_;

    //private elemetn for the target account
    int account2_id_; 
    int fund2_id_;


  
};


#endif //THEJOLLYBANKER_Transaction_H

