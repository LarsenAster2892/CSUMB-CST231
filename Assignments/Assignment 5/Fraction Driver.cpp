// -------- Test Fraction Module
// ------  Includes ------
#include <iostream>
#include <iomanip>
#include <string>
#include "FRACTION.H"
using std::cout;
using std::endl;
using std::cin;

int main(void)
{
	Fraction f1(2,3), f2(1,2), f3(4,5), f4(8,9);
	Fraction e1(2,3), e2(1,3), e3(3,6), e4(1,2);
	int intTmp = 0;

	cout << " The created fractions are:" << endl;
	cout << "f1 =" << f1 << endl;
	cout << "f2 =" << f2 << endl;
	cout << "f3 =" << f3 << endl;
	cout << "f4 =" << f4 << endl;
	cout << "e1 =" << e1 << endl;
	cout << "e2 =" << e2 << endl;
	cout << "e3 =" << e3 << endl;
	cout << "e4 =" << e4 << endl;

	cout << endl;


	cout << " The fractions comparisons are:" << endl;
   
	cout << "f2 < f1 " << ((f2 < f1) ? "True" : "False") << endl;
    cout << "f2 > f1 " << ((f2 > f1) ? "True" : "False")<< endl;
    cout << "f2 == f1 " << ((f2 == f1) ? "True" : "False")<< endl;
    cout << "f1 == e1 " << ((f1 == e1) ? "True" : "False")<< endl;
    cout << "f2 != f1 " << ((f2 != f1) ? "True" : "False")<< endl;
    cout << "f1 != e1 " << ((f1 != e1) ? "True" : "False")<< endl;

	cout << "f2 >= f1 " << ((f2 >= f1) ? "True" : "False")<< endl;
    cout << "f1 >= e1 " << ((f1 >= e1) ? "True" : "False")<< endl;
    cout << "f2 <= f1 " << ((f2 <= f1) ? "True" : "False")<< endl;
    cout << "f1 <= e1 " << ((f1 <= e1) ? "True" : "False")<< endl;
    cout << "f2 < e3 " << ((f2 < e3) ? "True" : "False")<< endl;

	cout << endl;


}

