/*
   File: address.h
   Description: address header file
   Author:  Joshua Santillan
   Email: santillanj125821@student.vvc.edu
*/
#ifndef ADDRESS_H
#define ADDRESS_H
#include<vector>
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include"address_book.h"
#include<sstream>
// just use a vector for this class retard
class Address{
        public:
        Address();
        void add_from_file(const std::string &f);
        void add_from_user();
        void search_book(const std::string &n) const;
        void save_book();
        void print();
        void change_address(const std::string &name, const std::string &new_address);
        void change_name(const std::string &name, const std::string &new_name);
        private:

        std::vector<AddressBook*> m_info;
};

#endif
