//********************************************************
// File Name   : Compare.h  
// Author      : Clarence Mitchell
// Assignment  : Number 4
// Date Due    : July 24, 2003 (11:59 PM)
// Description : (compare.h) Header file for Template class
// -----------------------------------------------------------             
// Class       : CISP400 - SUMMER 2003 MW 5:30PM
// Instructor  : Krofchok
// ********************************************************
#include <iostream>
#include <iomanip>
#include <string>

#ifndef COMPARE_H
#define COMPARE_H 

//
// Template function for Max Value
//

template <typename T>
const T & gmax(const T &a, const T &b) 
{
	if (a < b)
		return b;
	else
		return a;
}
//
// Template function for Min  Value
//
template <typename T>
const T & gmin(const T &a, const T &b) 
{
	if (a > b)
		return b;
	else
		return a;
}
//
// Template function for Max Array  Value
//
template <typename T>
const T & gmax(const T a[], int n) 
{
	int imax = 0;
	for (int i = 1; i < n; i++)
	  {
		if (a[i] > a[imax])
		{
			imax = i;
		}
	  }	
	return a[imax];
}
//
// Template function for Min Array  Value
//
template <typename T>
const T & gmin(const T a[], int n) 
{
	int imin = 0;
	for (int i = 1; i < n; i++)
	  {
		if (a[i] < a[imin])
		{
			imin = i;
		}
	  }	
	return a[imin];
}
#endif
