#using <mscorlib.dll>
#using <System.dll>
#using <System.Drawing.dll>
#using <System.Windows.Forms.dll>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
enum WidgetType {TEXTFIELD = 0, TEXTAREA = 1, SELECTLIST =2};
__gc class SimpleForm : public Form
{
public:
	SimpleForm();
	void SetWidget(WidgetType inWidget) { mwidget = inWidget; };


private:
	TextBox *txtBox;
	Label *txtLbl;
   // Use the Button class to create a button
	Button *btnClose;
	// Create an OnClick event for the button
	void CloseClick(Object *Sender, EventArgs *Args);
	
	WidgetType mwidget;
};

SimpleForm::SimpleForm()
{
	// --- draw form ----
	this->Text = S"Assignment Three Form";
	this->Size = Drawing::Size(400, 420);
	// Declare a pointer to the Icon class and use its constructor
	// to specify the name of the icon
	// (The Icon class is defined in the Drawing namespace)
	Drawing::Icon *IC = new Drawing::Icon("Assign3.ico");
	// Let this form know that you have an icon and assign it
	// to the Icon property of this form
	this->Icon = IC;
	this->MinimizeBox = true;	// enable minimize box
	this->MaximizeBox = false;  // disable maximize box
	// --- Create Label
	this->txtLbl = new Label();
	this->txtLbl->AutoSize = true;
	this->txtLbl->Location = Drawing::Point(8, 16);
	this->txtLbl->Size = Drawing::Size(28, 13);
	this->txtLbl->Text = "Label this is a test:";
	Controls->Add(this->txtLbl);

	// ---- create Textbox ---
	txtBox = new TextBox;
	int xPos = this->txtLbl->get_Right() + 4;
	txtBox->Location = Point(xPos, 16);
	txtBox->Enabled = false;
	txtBox->BackColor = Drawing::Color::White;

	txtBox->ForeColor = Drawing::Color::Black;
	txtBox->Text = "Testing 1 2 3";
	Controls->Add(txtBox);
	

	// Use the instance of the Button class to initialize the button
	btnClose = new Button;
	// Set the location of the button
	btnClose->Location = Point(115, 225);
	// The caption of the button
	btnClose->Text = S"&Close";
	// Let the button know that you have code for its OnClick event
	btnClose->Click += new EventHandler(this, CloseClick);
	// After creating the object, add it to the group
	// of controls that belong to this form
	this->Controls->Add(btnClose);
}

	
void SimpleForm::CloseClick(Object *Sender, EventArgs *Args)
{
	//CurrControl++;
	//if (CurrControl == LastControl)
	// This event fires when the user clicks the button
	//System::Windows::Forms::MessageBox::Show("Next Object?",
	//	            "Assignment 3 ",
	//				System::Windows::Forms::MessageBoxButtons::OK,
	//				System::Windows::Forms::MessageBoxIcon::Information);

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
