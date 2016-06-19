//********************************************************
// Name      : Clarence Mitchell
// Class     : CISP400 - SUMMER 2003 MW 5:30PM
// Instructor: Krofchok
// ********************************************************
//  HOMEWORK - Exercise 2B - Problem 1
//  (CLASS HEADER FILE)
// *******************************************************
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

//
// ------  Includes ------
#include <string>
//
// ------  Class Definition (inline) ------
class BankAccount
{
  private:
    std::string m_FullName;         // Full Name of Depositor
    long m_AccountNumber;           // Account Number of Deposit
    double m_Balance;				  // Balance of Account
  
 
  public:
	 
	BankAccount(std::string, long);
	BankAccount(std::string, long, double);
    
	std::string	Name() const { return m_FullName; }
	long AccountNumber() const { return m_AccountNumber; }
	double Balance() const { return m_Balance; }
	
	void Deposit(const double);
    void Withdrawal(const double);
    void DisplayData();
};
#endif
