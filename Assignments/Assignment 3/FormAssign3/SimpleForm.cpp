#using <mscorlib.dll>
#using <System.dll>
#using <System.Drawing.dll>
#using <System.Windows.Forms.dll>
#include <string>
#include "Widget.h"
//using std::string;

using namespace System;
using System::String;
using namespace System::Drawing;
using namespace System::Windows::Forms;

#include "SimpleForm.h"
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//
//  Definition of Form constructor
//
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

SimpleForm::SimpleForm()
{
	// --- draw form ----
	this->Text = S"Assignment Three Form";
	this->Size = Drawing::Size(400, 420);
	Drawing::Icon *IC = new Drawing::Icon("Assign3.ico");
	this->Icon = IC;
	this->MinimizeBox = true;	// enable minimize box
	this->MaximizeBox = false;  // disable maximize box
	

	btnClose = new Button;
	btnClose->Location = Point(155, 350);
	btnClose->Text = S"&Close";
	btnClose->Click += new EventHandler(this, CloseClick);
	this->Controls->Add(btnClose);
	
	CreateGroupBox();
}

SimpleForm::~SimpleForm()
{
	

}



//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//
//  Form Object Method for building and displaying 
//  TextField
//
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

void SimpleForm::ShowTextField(const TextField &tf)
{
	 
	// --- Create Label
	this->txtLbl = new Label();
	this->txtLbl->AutoSize = true;
	this->txtLbl->Location = Drawing::Point(8, 16);
	this->txtLbl->Size = Drawing::Size(28, 13);
	
	char *strLabel = new char[tf.label().length()+1];
    strcpy( strLabel, tf.label().c_str() );

	this->txtLbl->Text = strLabel;
	delete strLabel;

	Controls->Add(this->txtLbl);

	// ---- create Textbox ---
	txtBox = new TextBox;
	int xPos = this->txtLbl->get_Right() + 4;
	txtBox->Location = Point(xPos, 16);
	txtBox->Enabled = false;
	txtBox->BackColor = Drawing::Color::White;

	txtBox->ForeColor = Drawing::Color::Black;
	txtBox->AutoSize = true;
	txtBox->Text = Convert2Char(tf.value());
	Drawing::Font* tbf = txtBox->Font;
	txtBox->Width = int((double)(tf.width()+1) * (double)((tbf->SizeInPoints * ( 72.0/ 96.0))));
	Controls->Add(txtBox);


	int xWidth = int((double)(tf.width()) * (double)((tbf->SizeInPoints * ( 72.0/ 96.0))));
	Lbltxtb = new Label();
	Lbltxtb->AutoSize = false;
	Lbltxtb->Location = Drawing::Point(xPos+200, 36);
	Lbltxtb->Size = Drawing::Size(xWidth, 15);
	Lbltxtb->Text = Convert2Char(tf.value());
	Lbltxtb->Width = int((double)(tf.width()+2) * (double)((tbf->SizeInPoints * ( 72.0/ 96.0))));
	Lbltxtb->BackColor = System::Drawing::Color::White;
	Lbltxtb->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
	Controls->Add(this->Lbltxtb);


	//
	// Setup and display attribute information
	//
		//int tmpInt;
		LblNumItems->Visible = false;
		LblNumItemsb->Visible = false;
		LblHeight->Visible = false;
		LblHeightb->Visible = false;
		LblSizeb->Text = tf.size().ToString();
		LblMaxLengthb->Text = tf.maxlen().ToString();
		LblValLenthb->Text = tf.value().length().ToString();
		LblWidthb->Text = tf.width().ToString();
		LblValDatab->Text = Convert2Char(tf.value());

	
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//
//  Form Object Method for building and displaying 
//  TextArea
//
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

void SimpleForm::ShowTextArea(const TextArea &ta)
{
	 
	// --- Create Label
	this->txtLbl = new Label();
	this->txtLbl->AutoSize = true;
	this->txtLbl->Location = Drawing::Point(8, 16);
	this->txtLbl->Size = Drawing::Size(28, 13);
	
	char *strLabel = new char[ta.label().length()+1];
    strcpy( strLabel, ta.label().c_str() );

	this->txtLbl->Text = strLabel;
	delete strLabel;

	Controls->Add(this->txtLbl);

	// ---- create Textbox ---
	txtBox = new TextBox;
	int xPos = this->txtLbl->get_Right() + 4;
	txtBox->Location = Point(xPos, 16);
	txtBox->Enabled = false;
	txtBox->BackColor = Drawing::Color::White;

	txtBox->ForeColor = Drawing::Color::Black;
	txtBox->AutoSize = true;
	txtBox->Text = Convert2Char(ta.value());
	txtBox->Height = ta.height();
	txtBox->WordWrap = true;
	Drawing::Font* tbf = txtBox->Font;
	txtBox->Width = int((double)(ta.width()+1) * (double)((tbf->SizeInPoints * ( 72.0/ 96.0))));
	Controls->Add(txtBox);


	int xWidth = int((double)(ta.width()) * (double)((tbf->SizeInPoints * ( 72.0/ 96.0))));
	Lbltxtb = new Label();
	Lbltxtb->AutoSize = false;
	Lbltxtb->Location = Drawing::Point(xPos+200, 36);
	Lbltxtb->Size = Drawing::Size(xWidth, 15);
	Lbltxtb->Text = Convert2Char(ta.value());
	Lbltxtb->Width = int((double)(ta.width()+2) * (double)((tbf->SizeInPoints * ( 72.0/ 96.0))));
	Lbltxtb->BackColor = System::Drawing::Color::White;
	Lbltxtb->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
	Controls->Add(this->Lbltxtb);


	//
	// Setup and display attribute information
	//
		//int tmpInt;
		LblNumItems->Visible = false;
		LblNumItemsb->Visible = false;
		LblHeight->Visible = false;
		LblHeightb->Visible = false;
		LblSizeb->Text = ta.size().ToString();
		LblMaxLengthb->Text = ta.maxlen().ToString();
		LblValLenthb->Text = ta.value().length().ToString();
		LblWidthb->Text = ta.width().ToString();
		LblValDatab->Text = Convert2Char(ta.value());

	
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//
//  Form Object Method for Creating Groupbox
//
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

void SimpleForm::CreateGroupBox()
{
	GrpBox = new GroupBox;
	GrpBox->Location = Point(16, 100);
	GrpBox->Text = S"Attributes";
	GrpBox->Size = Drawing::Size(350, 200);

	
	LblSize = new Label();
	LblSize->AutoSize = true;
	LblSize->Location = Drawing::Point(8, 20);
	LblSize->Size = Drawing::Size(28, 13);
	LblSize->Text = "  Size: ";
	GrpBox->Controls->Add(LblSize);
	
	LblSizeb = new Label();
	LblSizeb->AutoSize = true;
	LblSizeb->Location = Drawing::Point(200, 20);
	LblSizeb->Size = Drawing::Size(40,15);
	LblSizeb->Text = "99999";
	LblSizeb->BackColor = System::Drawing::Color::White;
	LblSizeb->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
	GrpBox->Controls->Add(LblSizeb);



	LblWidth = new Label();
	LblWidth->AutoSize = true;
	LblWidth->Location = Drawing::Point(8, 40);
	LblWidth->Size = Drawing::Size(28, 13);
	LblWidth->Text = "  Width: ";
	GrpBox->Controls->Add(LblWidth);

	LblWidthb = new Label();
	LblWidthb->AutoSize = true;
	LblWidthb->Location = Drawing::Point(200, 40);
	LblWidthb->Size = Drawing::Size(40,15);
	LblWidthb->Text = "99999";
	LblWidthb->BackColor = System::Drawing::Color::White;
	LblWidthb->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
	GrpBox->Controls->Add(LblWidthb);


	
	LblHeight = new Label();
	LblHeight->AutoSize = true;
	LblHeight->Location = Drawing::Point(8, 60);
	LblHeight->Size = Drawing::Size(28, 13);
	LblHeight->Text = "  Height: ";
	GrpBox->Controls->Add(LblHeight);

	LblHeightb = new Label();
	LblHeightb->AutoSize = true;
	LblHeightb->Location = Drawing::Point(200, 60);
	LblHeightb->Size = Drawing::Size(40,15);
	LblHeightb->Text = "99999";
	LblHeightb->BackColor = System::Drawing::Color::White;
	LblHeightb->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
	GrpBox->Controls->Add(LblHeightb);
		
	LblMaxLength = new Label();
	LblMaxLength->AutoSize = true;
	LblMaxLength->Location = Drawing::Point(8, 80);
	LblMaxLength->Size = Drawing::Size(28, 13);
	LblMaxLength->Text = "  Max Length: ";
	GrpBox->Controls->Add(LblMaxLength);

	LblMaxLengthb = new Label();
	LblMaxLengthb->AutoSize = true;
	LblMaxLengthb->Location = Drawing::Point(200, 80);
	LblMaxLengthb->Size = Drawing::Size(40,15);
	LblMaxLengthb->Text = "99999";
	LblMaxLengthb->BackColor = System::Drawing::Color::White;
	LblMaxLengthb->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
	GrpBox->Controls->Add(LblMaxLengthb);
	
	LblNumItems = new Label();
	LblNumItems->AutoSize = true;
	LblNumItems->Location = Drawing::Point(8, 100);
	LblNumItems->Size = Drawing::Size(28, 13);
	LblNumItems->Text = "  Number Items: ";
	GrpBox->Controls->Add(LblNumItems);

	LblNumItemsb = new Label();
	LblNumItemsb->AutoSize = true;
	LblNumItemsb->Location = Drawing::Point(200, 100);
	LblNumItemsb->Size = Drawing::Size(40,15);
	LblNumItemsb->Text = "99999";
	LblNumItemsb->BackColor = System::Drawing::Color::White;
	LblNumItemsb->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
	GrpBox->Controls->Add(LblNumItemsb);
	
	LblValLenth = new Label();
	LblValLenth->AutoSize = true;
	LblValLenth->Location = Drawing::Point(8, 120);
	LblValLenth->Size = Drawing::Size(28, 13);
	LblValLenth->Text = "  Value Length: ";
	GrpBox->Controls->Add(LblValLenth);


	LblValLenthb = new Label();
	LblValLenthb->AutoSize = true;
	LblValLenthb->Location = Drawing::Point(200, 120);
	LblValLenthb->Size = Drawing::Size(40,15);
	LblValLenthb->Text = "99999";
	LblValLenthb->BackColor = System::Drawing::Color::White;
	LblValLenthb->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
	GrpBox->Controls->Add(LblValLenthb);
	
	LblValData = new Label();
	LblValData->AutoSize = true;
	LblValData->Location = Drawing::Point(8, 140);
	LblValData->Size = Drawing::Size(28, 13);
	LblValData->Text = "  Value Data: ";
	GrpBox->Controls->Add(LblValData);

	LblValDatab = new Label();
	LblValDatab->AutoSize = true;
	LblValDatab->Location = Drawing::Point(200, 140);
	LblValDatab->Size = Drawing::Size(40,15);
	LblValDatab->Text = "99999";
	LblValDatab->BackColor = System::Drawing::Color::White;
	LblValDatab->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
	GrpBox->Controls->Add(LblValDatab);

	//LblValData;
	
	Controls->Add(GrpBox);
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//
//  Form Oject Button Click Method
//
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

void SimpleForm::CloseClick(Object *Sender, EventArgs *Args)
{

	Close();
}


int __stdcall WinMain()
{
	SimpleForm *FM = new SimpleForm();
	Application::Run(FM);
	//System::Windows::Forms::MessageBoxOptions rtnOption;
	//	System::Windows::Forms::MessageBox::Show("Next Object?",
	//		            "Assignment 3 ",
	//					System::Windows::Forms::MessageBoxButtons::OK,
	//					System::Windows::Forms::MessageBoxIcon::Information);
	return 0;
}
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//
//  Function to convert string object to char*
//
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

char* Convert2Char(std::string &s)
{
char *c = new char[s.length() + 1];
strcpy( c, s.c_str() );
return c;
}