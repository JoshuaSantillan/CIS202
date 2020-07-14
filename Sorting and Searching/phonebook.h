/*
	Name: Joshua Santillan
	FileName: phonebook.h
	Date: 5/12/19
	Description: Phonebookclass class headerfile used for sorting/searching a vector of names through a file using the algorithm library for certain functions.
*/

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include "splitstring.h"
#include "listing.h"

class PhoneBook{
	
	std::vector<Listing*> v;
	
	public:
	
	PhoneBook(std::string file);
	void print();
	void sort_name();
	void sort_number();
	std::string find_name(const std::string &name);
	std::string find_number(const std::string &number);
	int binarysearch_name(const std::vector<Listing*> &v, int from, int to, const std::string &value);
	
	int binarysearch_number(const std::vector<Listing*> &v, int from, int to, const std::string &value);
};


#endif
