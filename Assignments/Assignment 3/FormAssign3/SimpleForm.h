#using <mscorlib.dll>
#using <System.dll>
#using <System.Drawing.dll>
#using <System.Windows.Forms.dll>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
#include "Widget.h"

#ifndef SIMPLEFORM_h
#define SIMPLEFORM_h

enum WidgetType {TEXTFIELD = 0, TEXTAREA = 1, SELECTLIST =2};
__gc class SimpleForm : public Form
{
public:
	SimpleForm();
	void SetWidget(WidgetType inWidget) { mwidget = inWidget; };
	void ShowTextField(const TextField &tf);
	void ShowTextArea(const TextArea &ta);
	//void ShowSelectList(const SelectList &sl);
	//void Finalize();
	~SimpleForm();

private:
	TextBox *txtBox;
	Label	*Lbltxtb;
	Label	*txtLbl;

	GroupBox *GrpBox;
	Label *LblSize;
	Label *LblSizeb;

	Label *LblWidth;
	Label *LblWidthb;
	Label *LblHeight;
	Label *LblHeightb;
	Label *LblMaxLength;
	Label *LblMaxLengthb;
	Label *LblNumItems;
	Label *LblNumItemsb;
	Label *LblValLenth;
	Label *LblValLenthb;
	Label *LblValData;
	Label *LblValDatab;

//	TextBox *tbxWidth;
//	TextBox *tbxHeight;
//	TextBox *tbxMaxLength;
//	TextBox *tbxNumItems;
//	TextBox *tbxValLenth;
//	TextBox *tbxValData;

	void CreateGroupBox();
   
	Button *btnClose;
	void CloseClick(Object *Sender, EventArgs *Args);
	
	WidgetType mwidget;

};

char* Convert2Char(std::string &s);

#endif