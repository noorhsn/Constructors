/*************************************************************************
* Learning different types of Constructors and Operator Overloading.
* 04-28-2025    Noor    First version of contructors and operator overloading.
**************************************************************************/

#include "String.h"

String operator + (String &s1, String &s2) {
	String result;
	char* temp = new char[strlen(s1.GetString()) + strlen(s2.GetString()) + 1];
	strcpy_s(temp, strlen(s1.GetString()) + 1, s1.GetString());
	strcat_s(temp, strlen(s1.GetString()) + strlen(s2.GetString()) + 1, s2.GetString());
	result.SetString(temp);
	return result;
}
std::ostream& operator<< (std::ostream& os, String& S) {
	os << S.GetString();
	return os;
}

int main(void) {
	using namespace std;
	String S1;	// Default Constructor
   S1.SetString("Hello World!"); // Set the string
   cout << S1 << endl;
   String S2(5, "Hello"); // Parameterized Constructor
   cout << S2 << endl;
   String S3(S2); // Copy Constructor
   cout << S3 << endl;
   String S4 = S2; // Copy Constructor
   cout << S4 << endl;
   S1 = S2; // Copy Assignment Operator
   cout << S1 << endl;
   String S5(std::move(S2)); // Move Constructor
   cout << S5 << endl;
   String S6 = std::move(S5); // Move Constructor
   cout << S6 << endl;      
   String S7; // Default Constructor
   S7.SetString("Noor Hasan!"); // Set the string
   cout << S7 << endl;
   S7 = std::move(S7); // Move Assignment Operator
   cout << S7 << endl;
   String S8(6, "World!"); // Parameterized Constructor
   cout << S8 << endl;
   String S9 = S7 + S8; // Concatenation Operator
   cout << S9 << endl;
   return 0;
}