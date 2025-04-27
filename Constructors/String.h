#pragma once

#include <iostream>
#include <cstring> // Include this header for strcpy_s

class String {
private:
	char* str{};
public:
	//Constructor
	String();
	//Destructor
	~String();
	//Parameterized Constructor
	String(int size, const char* newString);
	//Copy Constructor
	String(String& S);
	//Copy Assignment Operator
	String& operator=(String& S) noexcept;
	//Move Constructor
	String(String&& S);
	//Move Assignment Operator
	String& operator=(String&& S) noexcept;
	//Concatenation Operator
	String& operator+(const String S1) noexcept;
};