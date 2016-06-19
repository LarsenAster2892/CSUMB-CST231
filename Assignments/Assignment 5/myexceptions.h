//********************************************************
// File Name   : myexceptions.h  
// Author      : Clarence Mitchell
// Assignment  : Number 5
// Date Due    : July 31, 2003 (11:59 PM)
// Description : (myexceptions.h) Header file for custom 
//               exceptions
// -----------------------------------------------------------             
// Class       : CISP400 - SUMMER 2003 MW 5:30PM
// Instructor  : Krofchok
// ********************************************************

#include <string>
#include <iostream>
#include <exception>

#ifndef MYEXCEPTIONS_H
#define MYEXCEPTIONS_H


class IllegalArgumentException : public std::exception
{
 private:
	std::string umessage_;
  public:		
		IllegalArgumentException(std::string usermessage = "Illegal Argument") : exception()
		 { umessage_  = usermessage; };
		const char * what() { return umessage_.c_str(); }
};

class InvalidStateException : public std::exception
{
 private:
	std::string umessage_;

 public:		
		InvalidStateException(std::string usermessage = "Invalid State") : exception() 
		 { umessage_  = usermessage; };
		const char * what() { return umessage_.c_str(); }
};


#endif