#include<iostream>
#include "safestack.h"
#include<string>
#include<stack>
/*
	Name: Joshua Santillan
	Filename: main.cpp
	Date: apr 23 19
	Email: santj96@gmail.com


*/
int main(){

	try{
		SafeStack  s;
		s.push("Thing 1 in stack");	
      		s.top();
		s.pop();
		s.pop(); // should be caught
		s.top(); // should be caught
	}
	catch (SafeStackErr &e) {
		std::cerr << e.what() << std::endl;
		}

	std::cout << "Printing this after exception errors!" << std::endl;
	return 0;
}
