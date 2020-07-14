   /*
   File: address_book.cpp
   Description: address_book class functions just setters/getters
   Author:  Joshua Santillan
   Email: santillanj125821@student.vvc.edu
*/
#include "address_book.h"

AddressBook::AddressBook(const std::string& name, const std::string& address)
{
        m_name = name;
        m_address = address;
}
void AddressBook::set_name(const std::string& name)
{
        m_name = name;
}
void AddressBook::set_address(const std::string& address)
{
        m_address = address;
}
std::string AddressBook::get_name() const
{
        return m_name;
}
std::string AddressBook::get_address() const
{
        return m_address;
}
