//********************************************************
// File Name   : Widget Test Driver.cpp
// Author      : Clarence Mitchell
// Assignment  : Number 3
// Date Due    : July 17, 2003 (11:59 PM)
// Description : Test Driver file for Widget class
// -----------------------------------------------------------             
// Class       : CISP400 - SUMMER 2003 MW 5:30PM
// Instructor  : Krofchok
// ********************************************************

//--------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <string>
#include "Widget.h"

//--------------------------------------------------------------
int main()
{
	std::cout << "======= Now begining TextField Displays =====" << std::endl;
	std::cout << std::endl;

	
	TextField tf1("TextField 1");
	tf1.show();
	
	TextField tf2("TextField 2","TF Data 2");
	tf2.show();
	
	TextField tf3("TextField 3","TF Data 3",5);
	tf3.show();
	
	TextField tf4("TextField 4","TF Data 4",10,5);
	tf4.value("TF Data 4 - value"); 
	tf4.show();
	
	TextField tf5("TextField 5","TF Data 5 - value",10,40);
	tf5.show();
	
	TextField tf6(tf5);
	tf6.value("TF Data 6 - value");
	tf6.show();

	std::cout << std::endl;
	std::cout << "======= Now begining TextArea Displays =====" << std::endl;
	std::cout << std::endl;

	TextArea ta1("TextArea 1");
	ta1.show();
	
	TextArea ta2("TextArea 2","Text Area Data 2");
	ta2.show();
	
	TextArea ta3("TextArea 3","Text Area Data 3",5);
	ta3.show();
	
	TextArea ta4("TextArea 4","Text Area Data 4",10,5);
	ta4.show();

	TextArea ta5("TextArea 5","Text Area Data 5 - value",10,40);
	ta5.show();
	

	TextArea ta6("TextArea 6","ABCDEFGHIJKLMNOPQRSTUVWXYZ",5,15);
	ta6.show();
	
	TextArea ta7("TextArea 7","abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ",10,50,4);
	ta7.show();

	TextArea ta8("TTextArea 8","abcdefghijklmnopqrstuvwxyz",10,50,2);
	ta8.show();

	TextArea ta9(ta8);
	ta9.value("Text Area Data 9 abcdefghijklmnopqrstuvwxyz");
	ta9.height(3);
	ta9.show();

	std::cout << std::endl;
	std::cout << "======= Now begining SelectList Displays =====" << std::endl;
	std::cout << std::endl;


	SelectList sl1("Select List 1");
	sl1.add("Item 1");
	sl1.add("Item 2");
	sl1.show();
	sl1.value("Item 3");
	sl1.show();
	sl1.value("Item 2");
	sl1.show();
	SelectList sl2(sl1);
	sl2.add("Item 3");
	sl2.add("Item 4 - Longest line");
	sl2.add("Item 5");

	sl2.value("Item 3");
	sl2.show();

	return 0;
}