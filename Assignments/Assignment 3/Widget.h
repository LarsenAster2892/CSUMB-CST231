//********************************************************
// File Name   : Widget.h  
// Author      : Clarence Mitchell
// Assignment  : Number 3
// Date Due    : July 17, 2003 (11:59 PM)
// Description : Header file for Widget class
// -----------------------------------------------------------             
// Class       : CISP400 - SUMMER 2003 MW 5:30PM
// Instructor  : Krofchok
// ********************************************************
#include <iostream>
#include <iomanip>
#include <string>

#ifndef WIDGET_h
#define WIDGET_h
//
// Definition of structure for list linklist
// 
struct Node                          //	One Node in the list
{
	std::string ItemData;            //	data for list
    Node* pNext;                     //	Pointer to front link
};

typedef Node* NodePtr;			    // declare type pointer to node
//--------------------------------------------
//  Widget - Abstract Base Class
//-------------------------------------------
class Widget
{
  private:
    // --- CONSTANTS -----

	// --- Private Data Members ---
  protected:
	//static const char DEFAULT_LABEL = '\0';  Something that does not work.....
	//static const char DEFAULT_VALUE = '\0';

    std::string label_;
	std::string value_;							  	

	
	// --- private functions ----

  public:
    // --- Constructors ----
	Widget(std::string label, std::string value = "");
	
	// --- Destructor -----
	virtual ~Widget() {}

	// --- Copy constructor ----
	Widget(const Widget &w );

	// --- Accessors -----
	virtual std::string label() const = 0 { return (label_); }
	virtual std::string value() const = 0 { return (value_); }
	virtual int size() const = 0;
	// ---- Mutators -------
	virtual void value(std::string new_value) = 0;


	// --- Member Methods ---
	virtual void show() = 0;

};

//--------------------------------------------
//  TextField single line field
//-------------------------------------------
class TextField : public Widget
{
  private:
	
	// --- private functions ----
	std::string TruncValue (std::string inValue, int inLimit);
  
  protected:
	// --- CONSTANTS -------
	static const int DEFAULT_MAXLEN = 30;
	static const int DEFAULT_WIDTH = 30;

	// ---  Data Members ---
	int width_;
	int maxlen_;							  	

  public:
    // --- Constructors ----
	TextField(std::string inLabel,
		      std::string inValue = "",
			  int inWidth = DEFAULT_WIDTH,
			  int inMaxLen = DEFAULT_MAXLEN);


	// --- Destructor -----
	virtual ~TextField() {}

	// --- Copy constructor ----
	TextField(const Widget &tf );

	// --- Accessors -----
	int width() const { return (width_); }
	int maxlen() const { return (maxlen_); }
	virtual std::string label() const { return (Widget::label()); }
	virtual std::string value() const { return (Widget::value()); }
	virtual int size(void)const { return (width_); };	

	// ---- Mutators -------
	virtual void value(std::string new_value);


	// --- Member Methods ---
	virtual void show();
};

//--------------------------------------------
//  TextArea single line field
//-------------------------------------------
class TextArea : public TextField
{
  private:
	// --- Private Data Members ---
	static const int DEFAULT_HEIGHT = 4;

	int height_;
	
	// --- private functions ----
	void SetDefaults(void);

  public:
    // --- Constructors ----
	TextArea(std::string inLabel,
		     std::string inValue = "",
			 int inWidth = DEFAULT_WIDTH,
			 int inMaxLen = DEFAULT_MAXLEN,
			 int inHeight = DEFAULT_HEIGHT);

	// --- Destructor -----
	virtual ~TextArea();

	// --- Copy constructor -----
	TextArea(const TextArea &ta );

	// --- Accessors -----
	int height() const { return (height_); }

	int size() const {return (TextField::width() * height_); }
	// ---- Mutators -------
	virtual void value(std::string new_value) { TextField::value(new_value); };
	void height(int inHeight) { height_ = inHeight; }

	// --- Member Methods ---
	virtual void show();

};


class SelectList : public Widget
{
  private:
	Node* pFront_;								//	Points to first Item in list
	Node* pLast_;								// Points to last Item in list
	int NumberItems_;							// Number of Items in the list
	int LongItem_;								// Length of longest item is list

	// --- private functions ----
	void ClearList(void);						// Clear list by removing all nodes
	void CopyList(const SelectList & );			// Clears current and sets it equalant to passed
	bool FindItem(std::string s);				// Find an item in the list - returns true if found.

  public:

 
	// --- Constructors ----
	SelectList(std::string label);							
 	
	//-----	Destructor-----
	virtual ~SelectList();
	
	// ---- Copy constructor ----
	SelectList(const SelectList &sl );

	//---- Assessors -------
	int NumberItems() const				{ return NumberItems_; }
	virtual std::string label() const	{ return (Widget::label()); }
	virtual std::string value() const	{ return (Widget::value()); }
	int size()					const	{ return (LongItem_); };

	// ---- Mutators -------
	virtual void value(std::string new_value);

	// ---- Member Methods --------
	void add (std::string s);             
	virtual void show();


	//	------ operator (assignment) ---------
	SelectList& operator = (const SelectList & );

};
#endif