  /*
   File: address_book.h
   Description: address_book header file
   Author:  Joshua Santillan
   Email: santillanj125821@student.vvc.edu
*/
#ifndef ADDRESS_BOOK_H
#define ADDRESS_BOOK_H
#include<vector>
#include<iostream>

class AddressBook{
        public:
        AddressBook(const std::string &name, const std::string &address);
        void set_name(const std::string &name);
        void set_address(const std::string &address);
        std::string get_name() const;
        std::string get_address() const;

        private:
        std::string m_name, m_address;
};

#endif
