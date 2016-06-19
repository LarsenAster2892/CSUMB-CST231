//********************************************************
// File Name   : stockholding.h  
// Author      : Clarence Mitchell
// Assignment  : Number 4
// Date Due    : July 24, 2003 (11:59 PM)
// Description : (stockholding.h) Header file for Template class
//               Declaration for revised stock holding class
// -----------------------------------------------------------             
// Class       : CISP400 - SUMMER 2003 MW 5:30PM
// Instructor  : Krofchok
// ********************************************************
#include <iostream>
#include <iomanip>
#include <string>


#ifndef STOCKHOLDING_H
#define STOCKHOLDING_H

#include <string>
#include "array.h"
static const int NUM_HOLDINGS = 10;		

class StockHolding
{
  private:
    std::string company_;  // name of company offering stock
    int shares_;           // number of shares held by client
    double price_;         // price per share

  public:
    StockHolding(std::string company = "", int shares = 0,
      double price = 0);
    ~StockHolding();
	// --- Conversion Function ----
	operator double();


    std::string company() const { return company_; }
	void company(std::string cname) {company_ = cname;}
	int shares() const { return shares_; }
	void shares(int nshares) { shares_ = nshares;}
	double price() const { return price_; }
    double price(double price);
    double total_value() const { return price_ * shares_; }
	

    double buy(int shares, double price);
    double sell(int shares, double price);
    void show() const;
    const StockHolding & max_value(const StockHolding &s) const;
    StockHolding & operator=(const StockHolding &sh);


	// --- Friend functions ---
 
	friend std::ostream & operator<<(std::ostream &os, const StockHolding &sh);
};

std::ostream & operator<<(std::ostream &os, const StockHolding &sh);

class StockPortfolio
{
  private:


    std::string name_;											// name of portfolio Holder
   	Array<StockHolding>  stockholdings_;
  public: 

	  //StockPortfolio(std::string name = "") : name_(name),  stockholdings_() {};
	  StockPortfolio(std::string name = "");
	  //~StockPortfolio() {delete [] stockholdings_;};
	  ~StockPortfolio() {};

	   std::string holder() const { return name_; }

	   int total_shares() const;
	   double sum() const;


		StockHolding & operator[](int i);
		const StockHolding & operator[](int i) const;

	// --- Friend functions ---
	friend std::ostream & operator<<(std::ostream &os, const StockPortfolio &sp);
};

std::ostream & operator<<(std::ostream &os, const StockPortfolio &sp);

#endif

