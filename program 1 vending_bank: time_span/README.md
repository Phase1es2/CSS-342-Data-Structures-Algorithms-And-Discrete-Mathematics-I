Purpose 
 
This programming assignment will provide exercises in designing classes with proper 
abstraction and encapsulation.  Encapsulation and abstraction are key components of the C++ 
programming language as well as OOP in general.   In addition, the programming assignment 
will require understanding of operator overloading.   
 
Problem 1:  The Vending Bank 
 
Design (do not implement) a class which models the coin-operated “bank” part of a vending 
machine which sells snacks.  You only need to design the contract (.h file) and not the 
implementation (.cpp file).  Here is a start of vending_bank.h with one function already defined.  
The data member id_ is a unique identifier for the vending bank. 
 
vending_bank.h:  
 
#ifndef VENDING_BANK_H_ 
#define VENDING_BANK_H_ 
#include <string> 
using namespace std; 
 
// id_ is a unique identifier for the VendingBank much like a serial number 
class VendingBank 
{ 
 
 public: 
  VendingBank(); 
  VendingBank(int id); 
 
  //getters-setters 
  int id() const; 
 
FILL IN FURTHER PUBLIC FUNCTIONS HERE 
 
 
 private: 
  int id_ ;  
FILL IN DATA MEMBERS  
} 
#endif 
  
 
Problem 2:  TimeSpan 
 
Design and implement a TimeSpan class which represents a duration of time in hours, minutes, 
and seconds.  The order hours, minutes, and seconds should be respected in the constructor.  
 
As an example  
TimeSpan duration(1, 2, 3); 
is a duration of time of 1 hour, 2 minutes and 3 seconds. 
 
In the instances of the TimeSpan class you should store the values as integers in a normalized 
way.   The number of seconds should be between -60 and 60 when stored; number of minutes 
should be between -60 and 60 when stored.  That is, a user can create a TimeSpan object of 90 
seconds but it should be stored as 1 minute, 30 seconds.   
 
You do not need to worry about integer overflow for very big TimeSpan objects. 
 
Accessor functions required 
The TimeSpan class should implement the following member functions: 
 int hours() const;    return the number of hours as an int 
 int minutes() const;  return the number of minutes as an int  
 int seconds() const:     return the number of Seconds as an int 
 
 void set_time(int hours, int minutes, int seconds):   set the number of hours, minutes, 
seconds. 
 
Constructors 
 The class should define constructor(s) that receive various primitive types (specifically 
int, float, and double) and store them as integers.  Do appropriate rounding to maintain as 
much accuracy as possible down to the second as the smallest granularity. 
 
TimeSpan(1.5, 4, -10) represents 1 hour, 33 minutes, 50 seconds. 
 
If only one parameter is passed during initialization assume it is a second.  If there are two 
assume minutes and seconds (in that order). 
 
TimeSpan(7, -3) represents 6 minutes, 57 seconds. 
 
 
 
 
Operators 
 
 The class must overload and implement the following math operators:  addition, 
subtraction, Unary Negation. 
 
 The class must overload and implement all comparison operators:  ==, !=, <, <=, >, >= 
 
 The class must implement += and -= assignment statements as well. 
 
Stream I/O 
The class must implement the << and >> operators to work on streams: 
 
Input 
Take as input three values: hour, minutes, seconds and create appropriate class.  Assume 
that these will be integers. 
 
Output 
For formatting the following: 
TimeSpan duration1(1, 2, 3) 
std::cout << duration1; 
 
 Should output:   
Hours: 1, Minutes: 2, Seconds: 3 
 Please use this EXACT format. 
 
 
Turn In 
A .zip file which contains: 
 time_span.h  
 time_span.cpp 
 time_machine.cpp (your driver) 
 time_machine.exe (if using VS) or an executable time_machine  (if using Linux) 
 vending_bank.h 
Please make sure to spell the getter and setter functions exactly as I have them above.  Also, 
your overloads should follow appropriate signatures of they will not compile appropriately 
for the grader. 
 
 
