#include "String.h"

//String operator+(const String& S1, const String& S2) {
//	String result;
//	size_t length1 = strlen(S1.str) + strlen(S2.str) + 1;
//	result.str = strcat_s(new char[strlen(S1.str) + strlen(S2.str) + 1], S1.str, S2.str);
//	return String();
//}

int main(void) {
	String S1;	// Default Constructor
	String S2(5, "Hello"); // Parameterized Constructor
	String S3(S2); // Copy Constructor
	String S4 = S2; // Copy Constructor
	S1 = S2; // Copy Assignment Operator
	String S5(std::move(S2)); // Move Constructor
	String S6 = std::move(S2); // Move Constructor
	String S7;//Default Constructor
	S7 = std::move(S7); // Move Assignment Operator
	String S8(6,"World!");//Parameterized Constructor
	String S9 = S7 + S8; // Concatenation Operator
	return 0;
}