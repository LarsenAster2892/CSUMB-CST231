//********************************************************
// Name      : Clarence Mitchell
// Class     : CISP400 - SUMMER 2003 MW 5:30PM
// Instructor: Krofchok
// ********************************************************
//  HOMEWORK - Exercise 2B - Problem 1
//  (CLASS METHODS)
// *******************************************************
//
// ------  Includes ------
#include <iostream>
#include <iomanip>
#include "BANKACCOUNT.h"


//
// ------  Class Methods (inline) ------
BankAccount::BankAccount(std::string FullName,
							  long AccountNumber)
{
	m_FullName = FullName;
	m_AccountNumber = AccountNumber;
    m_Balance = 0;
}

BankAccount::BankAccount(std::string FullName,
							  long AccountNumber,
                              double OpenningDeposit)
{
	m_FullName = FullName;
	m_AccountNumber = AccountNumber;
   if (OpenningDeposit < 0) {
        std::cerr << "Transaction Error with Account :"
			      << m_AccountNumber 
				  << std::endl;

      std::cerr << "Amount of Deposit cannot be negative; "
          " Deposit set to zero" << std::endl;
	  std::cerr << "   Transaction Amount :" << OpenningDeposit << std::endl;
       m_Balance = 0;
      }
   else {
      m_Balance = OpenningDeposit;
    }

}

void BankAccount::Deposit(const double in_amount)
{
  double deposit_amount;
  if (in_amount < 0) {
        std::cerr << "Transaction Error with Account :"
			      << m_AccountNumber 
				  << std::endl;

	  std::cerr << "Amount of Deposit cannot be negative; "
      " Deposit set to zero" << std::endl;

 	  std::cerr << "   Transaction Amount :" << in_amount << std::endl;

     deposit_amount = 0;
  }
  else {
    deposit_amount = in_amount;
  }
  m_Balance += deposit_amount;
}

void BankAccount::Withdrawal(const double in_amount)
{
  if (in_amount < 0) {
        std::cerr << "Transaction Error with Account :"
			      << m_AccountNumber 
				  << std::endl;

      std::cerr << "Amount of Witthdrawal cannot be negative; "
                   "transaction aborted" << std::endl;
	 
	  std::cerr << "   Transaction Amount :" << in_amount << std::endl;
  
  }
  else 
	  if ((m_Balance - in_amount) < 0) {
        std::cerr << "Transaction Error with Account :"
			      << m_AccountNumber 
				  << std::endl;

		std::cerr << "Amount of Witthdrawal cannot exceed balance; "
		             "transaction aborted" << std::endl;
    
		std::cerr << "   Transaction Amount :" << in_amount << std::endl;

		}
	else {

			m_Balance -= in_amount;
		}
}



void BankAccount::DisplayData()
{
  std::ios_base::fmtflags io_flags = std::cout.flags();
  int io_precision = std::cout.precision();
  char io_fill = std::cout.fill();

  std::cout
      << std::left << std::setfill('.') << std::setw(30)
      << (m_FullName + ' ') << ' '
      << std::right << std::setfill(' ')
      << std::setw(5) << m_AccountNumber << " Balance "
      << std::fixed << std::setprecision(2)
      << " $"   << std::setw(10) << m_Balance
      << std::endl;

  std::cout.flags(io_flags);
  std::cout.fill(io_fill);
  std::cout.precision(io_precision);
}
