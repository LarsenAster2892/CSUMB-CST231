//********************************************************
// File Name   : Widget.ccp 
// Author      : Clarence Mitchell
// Assignment  : Number 3
// Date Due    : July 17, 2003 (11:59 PM)
// Description : SelectList Class non inline members
// -----------------------------------------------------------             
// Class       : CISP400 - SUMMER 2003 MW 5:30PM
// Instructor  : Krofchok
// ********************************************************
// ------  Includes ------
#include <iostream>
#include <iomanip>
#include <string>
#include "Widget.h"
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//  Widget - Abstract Base Class
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//-------------------------------------------------------------
//   Constructors  
//-------------------------------------------------------------
Widget::Widget(std::string label, std::string value )
{
    label_ = label;
	value_ = value; 
}
//-------------------------------------------------------------
//   Copy Constructor
//--------------------------------------------------------------
Widget::Widget(const Widget& newW ) 
{
	label_	= newW.label_;
	value_	= newW.value_;
}
//-------------------------------------------------------------
//  Mutators 
//-------------------------------------------------------------
void Widget::value(std::string new_value)
{
	value_ = new_value;
}

//-------------------------------------------------------------
//  Member Methods 
//-------------------------------------------------------------
//int Widget::size() const
//{
//	return ((int)label_.length() + (int)value_.length());
//}

void Widget::show(void)				
{
  
  std::string spacer(label_.length()+ 2, ' ');
  std::string borderline(value_.length() + 4, '*');
  
  std::cout << std::endl;
  std::cout << spacer << borderline << std::endl;
  std::cout << label_ << ": * " << value_ << " * " << std::endl;
  std::cout << spacer << borderline << std::endl;
}


//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//  TextField single line field
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//-------------------------------------------------------------
//   Constructors  
//-------------------------------------------------------------
TextField::TextField(std::string inLabel, 
					std::string inValue,
					int inWidth,
					int inMaxLen) : Widget(inLabel, TruncValue(inValue,inMaxLen))
{
	maxlen_ = inMaxLen;
	width_ = inWidth;
}


//-------------------------------------------------------------
//   Copy Constructor
//--------------------------------------------------------------
TextField::TextField(const TextField& newTF ) : Widget(newTF)
{
	width_	= newTF.width_;
	maxlen_ = newTF.maxlen_;
}
//-------------------------------------------------------------
//  Mutators 
//-------------------------------------------------------------
void TextField::value(std::string new_value)
{
	value_ = TruncValue(new_value, maxlen_);
}

//-------------------------------------------------------------
//  Member Methods 
//-------------------------------------------------------------

// -----------

void TextField::show(void)				
{
  std::string spacer(label_.length()+ 2, ' ');
  std::string borderline(width_ + 4, '*');
  std::string displayvalue(value_,0,width_);
  std::string padvalue((width_ - displayvalue.length()), ' ');
  std::string dashline(45, '-');

  std::cout << std::endl;
  std::cout << spacer << borderline << std::endl;
  std::cout << label_ 
	        << ": * " 
			<< displayvalue 
			<<  padvalue 
			<<" * " 
			<< std::endl;
  std::cout << spacer << borderline << std::endl;
  std::cout << std::endl;
  std::cout << dashline << std::endl;
  std::cout << "   ATTRIBUTES  " << std::endl;
  std::cout << dashline << std::endl;
  std::cout << "  Size         : " << (*this).size() << std::endl;
  std::cout << "  Max Length   : " << maxlen_ << std::endl;
  std::cout << "  Value Length : " << (int) value_.length() << std::endl;
  std::cout << "  Value Data   : " << value_ << std::endl;
  std::cout << dashline << std::endl;
  std::cout << std::endl << std::endl <<std::endl;


}

// -----------

std::string TextField::TruncValue(std::string inValue, int inLimit)
{
	std::string ReturnString = inValue.substr(0,inLimit);
	return (ReturnString);
}

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//  TextArea multiple lines field
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//-------------------------------------------------------------
//   Constructors  
//-------------------------------------------------------------
TextArea::TextArea(std::string inLabel,
		          std::string inValue,
			      int inWidth,
			      int inMaxLen,
				  int inHeight) : TextField(inLabel, inValue, inWidth,inMaxLen)
{
	height_ = inHeight;
}

//-------------------------------------------------------------
//   Destructors
//--------------------------------------------------------------
TextArea::~TextArea()
{
	
}
//-------------------------------------------------------------
//   Copy Constructor
//--------------------------------------------------------------
TextArea::TextArea(const TextArea& newTA ) : TextField(newTA)
{
	height_	= newTA.height_;
}
//-------------------------------------------------------------
//  Member Methods
//-------------------------------------------------------------

// -----------

void TextArea::show(void)				
{


   int SplitLines = ((int)value_.length() / width_) + ((int)value_.length() % width_ ? 1 : 0);
   int LastLine = (SplitLines < height_ ? SplitLines : height_);

   std::string spacer(label_.length()+ 2, ' ');	
   std::string borderline(width_ + 4, '*');
   std::string dashline(45, '-');  
   std::cout << std::endl;

   if (LastLine == 0){

	    borderline = "*****";

	   std::cout << spacer << borderline << std::endl;

       std::string displayvalue(" ");
	   
	   std::cout << label_  + ": "
				<< "* " 
				<< displayvalue 
				<< " * "; 

		std::cout << std::endl;

   }
   else{	
		std::string displayvalue;  
		std::cout << spacer << borderline << std::endl;
	   
	   for (int lines = 1, StartPos = 0;
				lines <= LastLine;
				lines++, StartPos += width_){

				std::string displayvalue(value_.substr(StartPos, width_));
				std::string padvalue((width_ - displayvalue.length()), ' ');


				std::cout << (lines == 1 ? label_  + ": ": spacer)
						<< "* " 
						<< displayvalue 
						<<  padvalue 
						<< " * "; 

				std::cout << std::endl;
				}
   }
	std::cout << spacer << borderline << std::endl;
    std::cout << std::endl;

	std::cout << std::endl;
	std::cout << dashline << std::endl;
	std::cout << "   ATTRIBUTES  " << std::endl;
	std::cout << dashline << std::endl;
	std::cout << "  Size         : " << (*this).size() << std::endl;
	std::cout << "  Width        : " << width_ << std::endl;
	std::cout << "  Height       : " << height_ << std::endl;
	std::cout << "  Max Length   : " << maxlen_ << std::endl;
	std::cout << "  Value Length : " << (int) value_.length() << std::endl;
	std::cout << "  Value Data   : " << value_ << std::endl;
	std::cout << dashline << std::endl;
	std::cout << std::endl << std::endl <<std::endl;


}

//
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//  SelectList -- Dropdown list
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//-------------------------------------------------------------
//   Constructors  
//-------------------------------------------------------------
SelectList::SelectList(std::string label) : Widget(label)
{
	NumberItems_ = LongItem_ = 0;
	pFront_ = pLast_ = NULL; 

}

//-------------------------------------------------------------
//  Denstructor
//-------------------------------------------------------------
SelectList::~SelectList()
{
	ClearList();
}

//-------------------------------------------------------------
//   Copy Constructor
//--------------------------------------------------------------
SelectList::SelectList(const SelectList& newSL ) : Widget(newSL)
{
    NumberItems_ = LongItem_ = 0;
	pFront_ = pLast_ = NULL; 

	CopyList(newSL);
}
//-------------------------------------------------------------
//  Mutators 
//-------------------------------------------------------------
void SelectList::value(std::string new_value)
{
	if (FindItem(new_value))
	   value_ = new_value;
}

//--------------------------------------------------------------
//  Member Methods
//--------------------------------------------------------------
//

void SelectList::add(std::string s)			
{
	Node* newnode = new Node;	   
	if (newnode != NULL){
		
		newnode->ItemData = s;				
		newnode->pNext = NULL;			
		
		if (pFront_ == NULL){
			pFront_ = newnode;
		}
		else{
			pLast_->pNext = newnode;
		}

		pLast_ = newnode;
		NumberItems_++;

		if ((int)s.length() > LongItem_) {
			LongItem_ = (int) s.length();
		}
	}	
}

// -----------

void SelectList::ClearList(void)
{
	while(pFront_ != NULL )
	{
		Node* temp = pFront_;
		pFront_ = pFront_->pNext;
		delete temp;
		NumberItems_--;
		
		// included for testing
		//std::cout << "Removing link." << std::endl;
	}
	pLast_ = NULL;
	LongItem_ = 0;
}

// -----------

void SelectList::CopyList(const SelectList &otherSL )
{
	if (NumberItems_ > 0)
		ClearList();

	if (otherSL.NumberItems_ > 0) {
	
		Node* current = otherSL.pFront_;	//	Set ptr to itemlist_ link

		while( current != NULL )		
		{
			add( current->ItemData );		//	Add data to this			
		    current = current->pNext;		//	Move to next link
        }

	    delete current;
	}

}

// -----------

bool SelectList::FindItem(std::string s)			
{
	bool ReturnVal = false;
    Node* pTmpNode = pFront_;

	for(int intLoop = 1; 
	   ((intLoop <= NumberItems_) && (!(ReturnVal)));
	    pTmpNode = pTmpNode->pNext, intLoop++)
		{
			ReturnVal = (pTmpNode->ItemData == s);
	    }
			
	return ReturnVal;

}
  
// -----------

void SelectList::show()		
{
	Widget::show();
	Node* CurrentNode = pFront_;				//	Set ptr to itemlist_ link
    std::string dashline(45, '-');  

	std::cout << std::endl;
	std::cout << " Available Selections are: " << std::endl;
	std::cout << dashline << std::endl;

	while ( CurrentNode != NULL )
	{
		std::cout << "  " << CurrentNode->ItemData << "  " << std::endl;	
		CurrentNode = CurrentNode->pNext;    
	}
	std::cout << dashline << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << dashline << std::endl;
	std::cout << "   ATTRIBUTES  " << std::endl;
	std::cout << dashline << std::endl;
	std::cout << "  Size         : " << (*this).size() << std::endl;
	std::cout << "  Number Items : " << NumberItems_ << std::endl;
	std::cout << "  Value Length : " << (int) value_.length() << std::endl;
	std::cout << "  Value Data   : " << value_ << std::endl;
	std::cout << dashline << std::endl;
	std::cout << std::endl << std::endl <<std::endl;

}
