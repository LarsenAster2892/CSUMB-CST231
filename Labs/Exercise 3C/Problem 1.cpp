//********************************************************
// Name      : Clarence Mitchell
// Class     : CISP400 - SUMMER 2003 MW 5:30PM
// Instructor: Krofchok
// ********************************************************
//  HOMEWORK - Exercise 3C - Problem 1
//  (CLASS METHODS)
// *******************************************************
//
// ------  Includes ------
#include <iostream>
#include <iomanip>
#include "TEMPERATURE.h"
//
// ------  Class Methods ------
// Method definitions for the Temperature class

//
//  ======== Temperature conversion functions ========================
//
double Temperature::FtoC (double ftemp)
{
	return ((ftemp - 32.0) / 1.8);
}
double Temperature::CtoF (double ctemp)
{
	return ((ctemp * 1.8) + 32.0);
}
double Temperature::KtoC (double ktemp)
{
	return (ktemp - 273.15);
}
double Temperature::CtoK (double ctemp)
{
	return (ctemp + 273.15);
}
//
// ------ Constructor ---
//
Temperature::Temperature(double inTemp, scales inScale)
{
  
	temp_ = inTemp;
	scale_ = inScale;

}


//
// ------  fahrenheit Assessor & mutator ---
//
double Temperature::fahrenheit() 
{
	Scale(FARRENHEIT);
	return (temp_);

}

void Temperature::fahrenheit(double temp)
{
	Scale(FARRENHEIT);
	temp_ = temp;
}


//
// ------  celsius Assessor & mutator ---
//
double Temperature::celsius() 
{
	Scale(CELSIUS);
	return (temp_);

}

void Temperature::celsius(double temp)
{
	Scale(CELSIUS);
	temp_ = temp;
}
//
// ------  kelvin Assessor & mutator ---
//
double Temperature::kelvin() 
{
	Scale(KELVIN);
	return (temp_);

}

void Temperature::kelvin(double temp)
{
	Scale(KELVIN);
	temp_ = temp;
}
//
// ------  scale mutator ---
//
void Temperature::Scale(scales inScale)
{
	if (scale_ == inScale)
	{
       return;
	}
	else
		switch (inScale)
		{
		case CELSIUS: 
					switch(scale_)
					{
					case FARRENHEIT: 
					     temp_ = FtoC( temp_);
					     scale_ = CELSIUS;
					     break;

					case KELVIN:
					     temp_ = KtoC( temp_);
					     scale_ = CELSIUS;
					     break;
					}
	      
				    break;
				  
		case FARRENHEIT: 
					switch(scale_)
					{
					case KELVIN:
				         temp_ = KtoC( temp_);

					case CELSIUS: 
					     temp_ = CtoF( temp_);
					     scale_ = FARRENHEIT;
					     break;
					}
			
					break;
				  
		case KELVIN:
					switch(scale_)
					{
					case FARRENHEIT:
						 temp_ = FtoC( temp_);

					case CELSIUS: 
						 temp_ = CtoK( temp_);
						 scale_ = KELVIN;
						 break;
					}
				    break;

		default: std::cerr << "Invalid SCALE. SCALE must be C, F or K";
		}

}

//
// ---- Comparison Operators
//



//
// --- STREAM OVERLOAD OPERATORS ---
std::ostream & operator<<(std::ostream &os, const Temperature &t)
{

    os  << t.temp_ 	<< (char) t.scale_;

	return os;
}
std::istream & operator>>(std::istream &is, Temperature &t)
{
	double temp = 0.0;
	char first_char, scale_char;
	scales temp_scale;
	
	is >> first_char;
	is.putback(first_char);

	if (first_char < '0' || first_char >'9') 
	{
		is.setf( std::ios::failbit);
	}
	else {
		bool success = true;
		success = success && (is >> temp);
		success = success && (is >> scale_char);

		if (success)
			switch (scale_char)
			{
				case 'C': temp_scale = CELSIUS;
						break;
				case 'F': temp_scale = FARRENHEIT;
						break;
				case 'K': temp_scale = KELVIN;
						break;
				default: success = false;
			}

		if (success){
			
			t = Temperature(temp, temp_scale);
		}
		else{
		
			is.setf( std::ios::failbit);
		}
	}
	return is;
}


//
// unary Operators
// 
Temperature  operator+(const Temperature &t)
{
 
  Temperature tmpy = t;

  double  tmpTemp;
  scales  tmpScale;

  switch (t.Scale())
  {
	  case 'C':
		  tmpScale = CELSIUS;
		   tmpTemp = tmpy.celsius() * 1.0;
		   break;
	  case 'F':
		  tmpScale = FARRENHEIT;
		   tmpTemp = tmpy.fahrenheit() * 1.0;
		   break;

	  case 'K':
		  tmpScale = KELVIN;
		   tmpTemp = tmpy.kelvin() * 1.0;
		   break;
  }
  return (Temperature(tmpTemp, tmpScale));
}



Temperature operator-(const Temperature &t)
{
 
  Temperature tmpy = t;

  double  tmpTemp;
  scales  tmpScale;

  switch (t.Scale())
  {
	  case 'C':
		   tmpScale = CELSIUS;
		   tmpTemp = tmpy.celsius() * (-1.0);
		   break;
	  case 'F':
		   tmpScale = FARRENHEIT;
		   tmpTemp = tmpy.fahrenheit() * (-1.0);
		   break;

	  case 'K':
		   tmpScale = KELVIN;
		   tmpTemp = tmpy.kelvin() * (-1.0);
		   break;
  }
  return (Temperature(tmpTemp, tmpScale));
}

Temperature operator+(const Temperature &a, const Temperature &b)
{
  Temperature tmpx = a;
  Temperature tmpy = b;

  double  tmpTemp;
  scales  tmpScale;

  switch (a.Scale())
  {
	  case 'C':
		   tmpScale = CELSIUS;
		   tmpTemp = tmpx.celsius() + tmpy.celsius();
		   break;
	  case 'F':
		   tmpScale = FARRENHEIT;
		   tmpTemp = tmpx.fahrenheit() + tmpy.fahrenheit();
		   break;

	  case 'K':
		   tmpScale = KELVIN;
		   tmpTemp = tmpx.kelvin() + tmpy.kelvin();
		   break;
  }
  return (Temperature(tmpTemp, tmpScale));

}

Temperature operator-(const Temperature &a, const Temperature &b)
{
  //Temperature tmpx = a;
  //Temperature tmpy = b;

  //double  tmpTemp;
  //char	  tmpScale;

  //switch (a.Scale())
  //{
	 // case 'C':
		//   tmpScale = 'C';
		//   tmpTemp = tmpx.celsius() - tmpy.celsius();
		//   break;
	 // case 'F':
		//   tmpScale = 'F';
		//   tmpTemp = tmpx.fahrenheit() - tmpy.fahrenheit();
		//   break;

	 // case 'K':
		//   tmpScale = 'K';
		//   tmpTemp = tmpx.kelvin() - tmpy.kelvin();
		//   break;
  //}
  return (a + (-b));

}