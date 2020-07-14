/*
   File: main.cpp
   Description: main.cpp file
   Author:  Joshua Santillan
   Email: santillanj125821@student.vvc.edu
*/
#include"address.h"
#include"address_book.h"
void usage();
int main(int argc, char *argv[])
{


        Address Book;

        if (argc > 1) {
                std::string filename = argv[1]; // filename = argument passed by paramater [1]
                Book.add_from_file(filename);
        }
        
        bool menu = true;
        while (menu) {
                std::cout
                        <<  "Address Book Menu:\n"
                        <<  "1) Add an entry\n"
                        <<  "2) Search for an address\n"
                        <<  "3) Change an entry\n"
                        <<  "4) Save to file\n"
                        <<  "5) Exit\n";
                int ans;
                std::cin >> ans;

                if (ans == 1) {
                        Book.add_from_user();
                }
                else if (ans == 2) {
                        std::cout << "What name are you searching for? ";
                        std::string name;
                        std::cin >> name;
                        Book.search_book(name);
                        std::cin.ignore();
                }
                else if (ans == 3) {
                        std::cout << "Whos address do you want to change?(name)\n"; 
                        std::cin.ignore();
                        std::string name;
                        std::getline(std::cin, name);
                        std::cout << "Change name(1) or Address(2)?\n";
                        int ans;
                        std::cin >> ans;
                        if (ans == 1) {
                                std::cout << "New name entry: ";
                                std::cin.ignore();
                                std::string new_name;
                                std::getline(std::cin, new_name);
                                Book.change_name(name, new_name);
                        }
                        else if (ans == 2) {
                                std::cout << "New Address entry: ";
                                std::cin.ignore();
                                std::string new_address;
                                std::getline(std::cin, new_address);
                                Book.change_address(name, new_address);
                        }
                }
                else if (ans == 4) {
                        Book.save_book();
                }
                else {
                        usage();
                        return 0;
        }

    
  }
      return 0;
}
void usage(){
        std::cout << "Error:" << std::endl;
        std::cout << "./main [input file] [output destination]" << std::endl;
        std::cout << " -- blank output destinateion -- " << std::endl;
}
