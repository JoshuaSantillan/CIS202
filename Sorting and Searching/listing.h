/*
	Name: Joshua Santillan
	FileName: listing.h	
	Date: 5/12/19
	Description: creates a listing class that gets a users name and number
*/
#ifndef LISTING_H
#define LISTING_H
#include<string>

class Listing {
	
	std::string m_name, m_number;
	
	public:
	Listing(const std::string &name, const std::string &number);
	std::string get_name() const;
	std::string get_number() const;
	
};
#endif
