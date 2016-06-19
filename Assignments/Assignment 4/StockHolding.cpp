//********************************************************
// File Name   : StockHolding.cpp
// Author      : Clarence Mitchell
// Assignment  : Number 3
// Date Due    : July 24, 2003 (11:59 PM)
// Description : Method definitions for revised stock holding class
// -----------------------------------------------------------             
// Class       : CISP400 - SUMMER 2003 MW 5:30PM
// Instructor  : Krofchok
// ********************************************************
// ------  Includes ------
// 
#include <iostream>
#include <iomanip>
#include "stockholding.h"
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//  StockHolding methods
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

StockHolding::StockHolding(std::string company, int shares,
  double price)
{
	// used for testing
	//std::cout << "Acquiring " << company << "..." << std::endl;

  company_ = company;
  if (shares < 0) {
    std::cerr << "Number of shares cannot be negative; "
      " shares set to zero" << std::endl;
    shares_ = 0;
  }
  else {
    shares_ = shares;
  }
  price_ = price;
}

StockHolding::~StockHolding()
{
  // used for testing	
  //std::cout << "Destructing " << company() << "..." << std::endl;
}
//
// --- Conversion function
//

StockHolding::operator double()
{
  return double(price_ * shares_);
}

double StockHolding::price(double price)
{
  double temp = price_;
  price_ = price;
  return temp;
}

double StockHolding::buy(int shares, double price)
{
  if (shares < 0) {
    std::cerr << "Number of shares purchased cannot be negative; "
      "transaction aborted" << std::endl;
    return 0;
  }
  else {
    shares_ += shares;
    price_ = price;
    return shares * price;
  }
}

double StockHolding::sell(int shares, double price)
{
  if (shares < 0) {
    std::cerr << "Number of shares sold cannot be negative; "
      "transaction aborted" << std::endl;
    return 0;
  }
  else if (shares > shares_) {
    std::cerr << "Number of shares sold cannot be greater than "
      "number of shares owned; transaction aborted" << std::endl;
    return 0;
  }
  else {
    shares_ -= shares;
    price_ = price;
    return shares * price;
  }
}

void StockHolding::show() const
{
	std::cout << (*this) << std::endl;

}

const StockHolding & StockHolding::max_value(
  const StockHolding &s) const
{
  if (s.total_value() > total_value())
    return s;
  else
      return *this;
}



StockHolding & StockHolding::operator=(const StockHolding &sh)
{
  if (&sh != this) 
     return (*this);

  company_ = sh.company();
  shares_ = sh.shares();
  price_ = sh.price();
  return (*this);
}


//
// stream insertion 
//
std::ostream & operator<<(std::ostream &os, const StockHolding &s)
{
  std::ios_base::fmtflags io_flags = os.flags();
  int io_precision = os.precision();
  char io_fill = os.fill();


  os   << std::left << std::setfill('.') << std::setw(30)
      << (s.company() + ' ') << ' '
      << std::right << std::setfill(' ')
      << std::setw(5) << s.shares() << " share(s) "
      << std::fixed << std::setprecision(2)
      << "@ $"   << std::setw(6) << s.price()
      << " = $" << std::setw(10) << s.total_value()
      << std::endl;
 

  os.flags(io_flags);
  os.fill(io_fill);
  os.precision(io_precision);

  return os;
}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//  StockPortfolio methods
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

StockPortfolio::StockPortfolio(std::string name):  stockholdings_(NUM_HOLDINGS,StockHolding())
{
	name_ = name;	
	

}


int StockPortfolio::total_shares() const
{
  int return_value = 0;
  StockHolding tmp;
  for(int ia = 0; ia < NUM_HOLDINGS ; ia++)
  {
	
	  return_value += stockholdings_[ia].shares();
  }
  return return_value;
}

double StockPortfolio::sum() const
{
	return (stockholdings_.sum());
}



// 
// operator functions
//
StockHolding & StockPortfolio::operator[](int i)
{
  
  return (stockholdings_[i]);
}

const StockHolding  & StockPortfolio::operator[](int i) const
{
	return (stockholdings_[i]);
}
//
// stream insertion 
//
std::ostream & operator<<(std::ostream &os, const StockPortfolio &sp)
{
  std::ios_base::fmtflags io_flags = os.flags();
  int io_precision = os.precision();
  char io_fill = os.fill();

  os   << std::left << std::setfill('.') << std::setw(30)
      << (sp.holder() + ' ') << ' '
      << std::right 
      << std::setfill(' ')
      << std::setw(10)
	  << std::fixed 
	  << std::setprecision(2)
      << sp.sum()
      << std::endl;   
 
  for (int i = 0; i < 10; i++)
	  os << sp[i];

  os.flags(io_flags);
  os.fill(io_fill);
  os.precision(io_precision);

  return os;
}