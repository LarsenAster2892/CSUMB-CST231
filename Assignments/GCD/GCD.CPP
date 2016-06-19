// --- Test GCD thing ----
#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <iomanip>

int gcd(int, int);

int main()
{
	int value1;
	cout << "Enter Numerator:";
	cin >> value1;

	int value2;
	cout << "Enter Demoninator:";
	cin >> value2;
	int minvalue, maxvalue;
	if (value1 < value2) {
		minvalue = value1;
		maxvalue = value2;
	}
	else{
		minvalue = value2;
		maxvalue = value1;
	}


	cout << "The Greatest Common Divisor for "
		 << value1 << " / " << value2 
		 << " is "
		 << gcd(minvalue, maxvalue)
		 << endl;
	cout << endl;
	return 0;
}



int gcd( int num1, int num2 )

{
	
	int remainder = num2 % num1;
	
	if ( remainder != 0 )
		return gcd( remainder,num1 );
	
	return num1;
}
