//********************************************************
// File Name   : Widget Test Driver.cpp
// Author      : Clarence Mitchell
// Assignment  : Number 3
// Date Due    : July 17, 2003 (11:59 PM)
// Description : Test Driver file for Widget class (Form)
// -----------------------------------------------------------             
// Class       : CISP400 - SUMMER 2003 MW 5:30PM
// Instructor  : Krofchok
// ********************************************************

//--------------------------------------------------------------
#using <mscorlib.dll>
#using <System.dll>
#using <System.Drawing.dll>
#using <System.Windows.Forms.dll>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;



#include <iostream>
#include <iomanip>
#include <string>
#include "Widget.h"
#include "SimpleForm.h"

//--------------------------------------------------------------
int main()
{
	SimpleForm * f1 = new SimpleForm();
	f1->SetWidget(TEXTFIELD);
	TextField tf5("TextField 5","12345678 - value",5,40);

	tf5.show();
	f1->ShowTextField(tf5);
	f1->ShowDialog();
    delete f1;

	SimpleForm * f2 = new SimpleForm();
    TextArea ta3("TextArea 3","Text Area Data 3",5);
	ta3.show(); 
	f2->ShowTextArea(ta3);
	f2->ShowDialog();
	delete f2;
	
	return 0;
}