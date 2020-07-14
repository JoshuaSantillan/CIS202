/*
	Name: Joshua Santillan
	FileName: splitstring.h	
	Date: 5/12/19
	Description: pauls sample code for splitting a string and reading through a csv file easier
*/
#ifndef SPLITSTRING_H
#define SPLITSTRING_H
#include<iostream>
#include<string>
#include<vector>

class splitstring : public std::string {
	
	std::vector<std::string> flds;

	public:
	splitstring(const char *s) : std::string(s){
	};

	splitstring(const std::string &s) : std::string(s) {
	};
	std::vector<std::string>& split (char delim, int rep =0);
};
#endif
