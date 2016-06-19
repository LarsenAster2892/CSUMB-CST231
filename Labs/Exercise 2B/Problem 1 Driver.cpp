//********************************************************
// Name      : Clarence Mitchell
// Class     : CISP400 - SUMMER 2003 MW 5:30PM
// Instructor: Krofchok
// ********************************************************
//  HOMEWORK - Exercise 2B - Problem 1
//  (DRIVER)
// *******************************************************
//
// ------  Includes ------
#include <iostream>
#include "BANKACCOUNT.h"
//
// ------  Main (Driver) ------
int main()
{
 
  BankAccount Account1("Peter Otool",22299);
  BankAccount Account2("Bob Dole", 33399, 300.00);

  std::cout << " Accounts Created as follows:"       << std::endl;
  std::cout << "-----------------------------------" << std::endl;
  Account1.DisplayData();
  Account2.DisplayData();


  Account1.Deposit(100.00);
  Account2.Withdrawal(100.00);
  std::cout << std::endl;

  std::cout << " Accounts Updated to the following:" << std::endl;
  std::cout << "-----------------------------------" << std::endl;
  Account1.DisplayData();
  Account2.DisplayData();

  std::cout << std::endl;
  Account1.Deposit(-100.00);
  Account2.Withdrawal(-100.00);
  Account1.Withdrawal(300.00);

  std::cout << std::endl;
  std::cout << " Accounts Updated to the following:" << std::endl;
  std::cout << "-----------------------------------" << std::endl;
  Account1.DisplayData();
  Account2.DisplayData();

  std::cout << std::endl;
  std::cout << " Names for Accounts :" << std::endl;
  std::cout << "-----------------------------------" << std::endl;
  std::cout << Account1.Name() << std::endl;
  std::cout << Account2.Name() << std::endl;

  std::cout << std::endl;
  std::cout << " Numbers for Accounts :" << std::endl;
  std::cout << "-----------------------------------" << std::endl;
  std::cout << Account1.AccountNumber() << std::endl;
  std::cout << Account2.AccountNumber() << std::endl;

  
  std::cout << std::endl;
  std::cout << " Balances for Accounts :" << std::endl;
  std::cout << "-----------------------------------" << std::endl;
  std::cout << Account1.Balance() << std::endl;
  std::cout << Account2.Balance() << std::endl;


}

