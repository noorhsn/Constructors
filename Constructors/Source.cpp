#include "String.h"

using namespace std;
//Constructor
String::String() {
	str = new char[1];
	str[0] = '\0';
	cout << "Default Constructor Called\n";
}
//Destructor
String::~String() {
	delete[] str;
	cout << "Destructor Called\n";
}
//Parameterized Constructor
String::String(int size, const char* newString) {
	delete[] str; // Free the existing memory
	size_t length = strlen(newString)+1; // Calculate the length of the new string
	str = new char[length]; // Allocate memory for the string
	strcpy_s(str, length, newString); // Copy the new string
	cout << "Parameterized Constructor Called\n";
}
//Copy Constructor
String::String(String& S) {
	size_t length = strlen(S.str) + 1; // Calculate the length of the source string
	str = new char[length]; // Allocate memory for the string
	strcpy_s(str, length, S.str);
	cout << "Copy Constructor Called\n";
}
// Update the copy assignment operator
String& String::operator=(String& S) noexcept {
   if (this != &S) {
       delete[] str; // Free the existing memory
       size_t length = strlen(S.str) + 1; // Calculate the length of the source string
       str = new char[length]; // Allocate memory for the string
       strcpy_s(str, length, S.str); // Use the correct overload of strcpy_s
   }
   std::cout << "Copy Assignment Operator Called\n";
   return *this;
}
//Move Constructor
String::String(String&& S){
	if (this != &S) {
		str = S.str;
		S.str = nullptr;
	}
	cout << "Move Constructor Called\n";
}
//Move Assignment Operator
String& String::operator=(String&& S) noexcept {
	if (this != &S) {
		delete[] str;
		str = S.str;
		S.str = nullptr;
	}
	cout << "Move Assignment Operator Called\n";
	return *this;
}
//Concatenate two strings
String& String::operator+(const String S1) noexcept {
	String result;
	size_t length1 = strlen(str) + strlen(S1.str) + 1; // Calculate the length of the new string
	result.str = new char[length1]; // Allocate memory for the new string
	strcpy_s(result.str, length1, str); // Copy the first string
	strcat_s(result.str, length1, S1.str); // Concatenate the second string
	//result.str = strcat_s(new char[strlen(str) + strlen(S1.str) + 1], str, S1.str);
	cout << "Concatenation Operator Called\n";
	return result;
}