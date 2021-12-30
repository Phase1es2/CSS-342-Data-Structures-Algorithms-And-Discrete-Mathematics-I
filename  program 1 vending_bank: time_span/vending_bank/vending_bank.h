#ifndef VENDING_BANK_H_
#define VENDING_BANK_H_
#include <string>
using namespace std;

class VendingBank {
 public:
  VendingBank();
  VendingBank(int id);
  VendingBank(int id, int pennies, int nickels, int dimes, int quarters,
              int halves);
  VendingBank(int id, int amount);
  ~VendingBank();

  // getters-setters

  int getPennies() const;
  int getNickels() const;
  int getDimes() const;
  int getQuarters() const;
  int getHalves() const;
  int getID() const;

  void setPennies(const int& num);
  void setNickels(const int& num);
  void setDimes(const int& num);
  void setQuarters(const int& num);
  void setHalves(const int& num);
  void setID(const int& id);

  // actions
  bool addCoins(int pennies, int nickels, int dimes, int quarters, int halves);
  bool removeCoins(int pennies, int nickels, int dimes, int quarters,
                   int halves);
  bool canMakeChange(int amount) const;
  bool isEmptey() const;

  // Op Overloads
  VendingBank operator+(const VendingBank& vb) const;
  VendingBank operator+=(const VendingBank& vb);

  VendingBank operator!=(const VendingBank& vb) const;
  VendingBank operator==(const VendingBank& vb) const;

  VendingBank operator-(const VendingBank& vb) const;
  VendingBank operator-=(const VendingBank& vb);

  friend ostream& operator<<(ostream& stream, VendingBank& vb)

      private : int id_;
  int pennies_;
  int nickels_;
  int dimes_;
  int quarters_;
  int halves_;
  Coins makeChange(int amount);
};

#endif
