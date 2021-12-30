#include "transaction.h"




Transaction::Transaction(char type, int AccountID, int FundID, int Amount)
{
   
    type_ = type;
    account_id_ = AccountID;
    fund_id_ = FundID;
    amount_ = Amount;
    setTransactiontatment(true);
}

Transaction::Transaction(char type, int AccountID, int FundID, int AccountID2, int FundID2, int Amount)
{
    type_ = type;
    account_id_ = AccountID;
    fund_id_ = FundID;
    account2_id_ = AccountID2;
    fund2_id_ = FundID2;
    amount_ = Amount;
    setTransactiontatment(true);
}

Transaction::Transaction(char type, int AccountID)
{
    type_ = type;
    account_id_ = AccountID;
    setTransactiontatment(true);
}

Transaction::Transaction(char type, int AccountID, int FundID)
{
    type_ = type;
    account_id_ = AccountID;
    fund_id_ = FundID;
    setTransactiontatment(true);
}

Transaction::Transaction(char type, int AccountID, string LastName, string FirstName)
{
    type_ = type;
    account_id_ = AccountID;
    last_name_ = LastName;
    first_name_ = FirstName;
    setTransactiontatment(true);
}

char Transaction::getType() const
{
    return type_;
}

int Transaction::getAccountID() const
{
    return account_id_;
}

int Transaction::getAccountID2() const
{
    return account2_id_;
}

int Transaction::getFundID() const
{
    return fund_id_;
}

int Transaction::getFundID2() const
{
    return fund2_id_;
}

int Transaction::getAmount() const
{
    return amount_;
}

string Transaction::getFirstName() const
{
    return first_name_;
}

string Transaction::getLastName() const
{
    return last_name_;
}

bool Transaction::setTransactiontatment(bool Statment)
{
    s_ = Statment;
    return true;
}

bool Transaction::getTransactiontatment() const
{
    return s_;
}

ostream& operator<<(ostream& out, const Transaction& t)
{
    if (t.getType() == 'D' || t.getType() == 'W')
    {
        out << " " << t.getType() << " " << t.getAccountID() << " " << t.getFundID() << " " << t.getAmount();
    }
    else if (t.getType() == 'T')
    {
        out << " " << t.getType() << " " << t.getAccountID() << " " << t.getFundID() << " " << t.getAccountID2() << " " << t.getFundID2() << " " << t.getAmount();
    }
    if (!t.getTransactiontatment())
    {
        out << " (Failed)" << endl;
    }

    return out << endl;
}



