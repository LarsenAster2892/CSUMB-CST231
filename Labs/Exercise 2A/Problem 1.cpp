//********************************************************
// Name      : Clarence Mitchell
// Class     : CISP400 - SUMMER 2003 MW 5:30PM
// Instructor: Krofchok
// ********************************************************
//  HOMEWORK - Exercise 2A - Problem 1
// *******************************************************
//
// ------  Includes ------
#include <iostream>
#include <iomanip>
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
    void Deposit(const double);
    void Withdrawal(const double);
    void DisplayData();
};
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

}

