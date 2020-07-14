/*
	Name: Joshua Santillan
	File: main.cpp
	Email: Santillanj125821@student.vvc.edu
	Description: main calling my programs functions
*/
#include<iostream>
#include<vector>
#include<string>
#include "bigint.h"

int main(){

	BigInteger num1("123456789");
	BigInteger num2("987654321");
	
	std::cout << num1.integer() << " * " << num2.integer() << " = ";
	std::cout << num1 * num2 << std::endl;
	
	std::cout << num1.integer() << " - " << num2.integer() << " = ";
	std::cout << num1 - num2 << std::endl;
	
	std::cout << num1.integer() << " + " << num2.integer() << " = ";
	std::cout << num1 + num2 << std::endl;
	return 0;
}
