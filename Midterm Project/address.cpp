/*
   File: address.cpp
   Description: reads in info from user or from file storing addresses passing through a pointer vector of objects
   Author:  Joshua Santillan
   Email: santillanj125821@student.vvc.edu
*/

#include"address.h"

Address::Address(){
        //vectors construct themselves
}

void Address::add_from_file(const std::string &f){

        std::ifstream input(f, std::ios::in);
        if(input.is_open()){
                std::string name, address;
                while(std::getline(input,name) && std::getline(input, address)){
                        m_info.push_back(new AddressBook(name, address));
                }
                input.close();
        }
}

void Address::add_from_user(){

        std::string name, address;
        std::cout << "Enter a name to add to the address book:\n";
        std::cin.ignore();
        std::getline(std::cin, name);
        std::cout << "Enter an address to add to the address book:\n";
        std::cin.ignore();
        std::getline(std::cin, address);
        AddressBook *a = new AddressBook(name, address);
        m_info.push_back(a);
}

void Address::search_book(const std::string &n) const{

                for(int i = 0; i < m_info.size(); i++){
                        if( n == m_info[i]->get_name()){
                                std::cout << m_info[i]->get_name() << "\n" << m_info[i]->get_address() + "\n\n";
                        }

                }
}

void Address::change_address(const std::string &name, const std::string &new_address){

        for (auto info : m_info){
                if ( info->get_name() == name){
                        info->set_address(new_address);
                }
                else{
                        std::cout << "The name you entered is not in the book, cannot update address";
                }
        }
}
void Address::change_name(const std::string &name, const std::string &new_name){

        for (auto info : m_info){
                if ( info->get_name() == name){
                        info->set_name(new_name);
                }
                else{
                        std::cout << "The name you entered is not in the book, cannot update name";
                }
        }
}
void Address::print(){

        for(auto list : m_info){
                std::cout << list->get_name() + "\n";
        }
}
void Address::save_book(){

        std::ofstream book("addressbook.txt", std::ios::out);
        if(book.is_open()){
                book << " Address Book: \n";
                for(auto info : m_info){

                        book << info->get_name() << "\n" <<  info->get_address() << "\n";
                }
                book.close();
        }
}
