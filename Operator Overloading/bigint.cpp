/*
	Name: Joshua Santillan
	File: bigint.cpp
	Email: Santillanj125821@student.vvc.edu
	Description: Big integer function using vectors to convert numbers from strings to ints and back into strings for a big number
*/
#include"bigint.h"
#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>

BigInteger::BigInteger(){

}

BigInteger::BigInteger(const std::string &number){
	convert(number);
}

std::string BigInteger::integer() const {
	
	return m_number;

}

void BigInteger::convert(const std::string &number){

	m_number = number;

	if(m_number[0] != '-') // if the number not negative
	{
		for(int i =0; i < m_number.size(); i++){
			m_digit.push_back((m_number[i] - '0')); 
			// push the numbers as char into vector
		}
	}
	else if(m_number[0] == '-') // if the number is negative
	{
		for(int i = 0; i < m_number.size(); i++) {
			if(m_number[i] == '-') {
				m_number.erase(m_number.begin()+i);
			}
		}
	
// begin at the starting posiition and add 1 to delete the negative from the number for later for future use
		for (int i = 0; i < m_number.size(); i++) {
			m_number.push_back( m_number[i] -'0' );
		}
			// adding each iteration number to the digit
		change_sign(m_digit);
			// changes each number to be negative
		m_number.insert(m_number.begin(),'-');
			// will add the negative to the beginning of the number
	}
}

std::vector<int> BigInteger::digits() const {

	return m_digit;
}

// doing operator functions.

BigInteger BigInteger::operator*(const BigInteger &second_number) {

	BigInteger ans("0");

	for(int i = digits().size() - 1; i >= 0; i--) {
		for(int j = second_number.digits().size() -1; j >=0; j--) 
		{
			int tmp = std::abs(digits()[i] * second_number.digits()[j] );

			std::string str_tmp = std::to_string (tmp);

			power(str_tmp, (((digits().size() -1) - i) + ((second_number.digits().size()-1) -j)));
			ans = ans + BigInteger(str_tmp);
		}
	}
	// have to ensure/make sure a number is negative, but not both answers can be negative.

	if((integer()[0] == '-' || second_number.integer()[0] == '-') && !(integer()[0] == '-' && second_number.integer()[0] == '-')){
		std::string buffer = ans.integer();
		buffer.insert(buffer.begin(), '-');
		ans = BigInteger(buffer);
	}
	return ans;
}

BigInteger BigInteger::operator+(const BigInteger &second_number) {
  
  	std::string str_tmp;
 	std::vector<int> swap_first = reverse(BigInteger(integer()) );  
	// left hand side
    	std::vector<int> swap_second = reverse(second_number); 
	// right hand side number
    	levels(swap_first, swap_second);   
	//declaring a vector that will do opperations
    	std::vector<int> tmp(swap_first.size()); 
	

    int prev = 0;     // keeping track of previous with 0 place holder
    for(int i = 0; i < swap_first.size(); i++) {
        int next = swap_first[i] + swap_second[i];
        tmp[i] += next % 10;    // gets ones place 

        // if it is neccesary to push back more 0s
        if(i == tmp.size() - 1 && ( next + (prev / 10) > 9 || tmp[i] > 9 ) ) {
            tmp.push_back(0); // add space using 0s if number is 10 or higher
        }
        if(tmp[i] > 9) {
            tmp[i] -= 10; 
            tmp[i+1] += 1; 
        }

        tmp[i+1] += next / 10;  // division to extract the tenths place
        prev = next;
    }

    if(tmp[tmp.size() - 1] < 0) { // if the number is negative change reverse
        change_sign(tmp);
        str_tmp += "-";        
    }

    for(int i = 0; i < tmp.size(); i++) {
        if( (tmp[i] < 0) && (i < tmp.size() - 1) ) {
            tmp[i] += 10;     // borrow
            tmp[i+1] -= 1;
        }
    }
   
   	// converion back into a string
    for(int i = tmp.size() - 1; i >= 0; i--) {  
        str_tmp += std::to_string( tmp[i] );
    }

    return BigInteger(str_tmp);  
}

BigInteger BigInteger::operator-(const BigInteger &second_number) {
    if(second_number.integer()[0] == '-') { // if second integer is negative and being subtracted
        std::string str_second = second_number.integer();
        str_second.erase(str_second.begin() ); // remove the '-' sign from the number for operations and treat it as a positive.
        BigInteger second_number(str_second);
        BigInteger first = BigInteger(integer());
        return first + second_number; // add the two
    } else {                                                            
        BigInteger negative_second = BigInteger("-" + second_number.integer() );  
	// if negative add a - 
	    // if a positive number is being subtracted from
        BigInteger first = BigInteger(integer());
        return first + negative_second;  // add the two
    }
}

std::vector<int> BigInteger::reverse(const BigInteger &sign) {
    std::vector<int> tmp;
    for(int i = sign.digits().size() - 1; i >= 0; i--) {  
	    //reverse the vector
        tmp.push_back(sign.digits()[i]);
    }

    return tmp;    
    //makes/returns a reversed vector
}



void BigInteger::levels(std::vector<int> &first_number, std::vector<int> &second_number) {
    if(first_number.size() > second_number.size()) {
        std::vector<int> tmp = second_number;
        for(int i = second_number.size(); i < first_number.size(); i++) {    // determine which vector is longer
            tmp.push_back(0); // will add 0s to the end of a number until they become equal sizes
        }
        second_number = tmp;
    } 
    else {
        std::vector<int> tmp = first_number;
        for(int i = first_number.size(); i < second_number.size(); i++) {
            tmp.push_back(0);
        }
        first_number = tmp;
    }
}


void BigInteger::power(std::string &raise, int level){

	// this loop will work for the levels function and raising numbers
	for(int i = 0; i < level; i++){
		raise += "0";
		// this will add a 0 if the number is >=10
	}
}
template<class T> 
	void BigInteger::change_sign(T &original){
		
		for(int i = 0; i < original.size(); i++) {
			if(original[i] > 0) {
		// Teke has a great mind and shared his switch statement, understanding that if the number appears to be positive to return the oppisite.
		switch (original[i]) {
                case 0: original[i] = 0; break;
                case 1: original[i] = -1; break;
                case 2: original[i] = -2; break;
                case 3: original[i] = -3; break;
                case 4: original[i] = -4; break;
                case 5: original[i] = -5; break;
                case 6: original[i] = -6; break;
                case 7: original[i] = -7; break;
                case 8: original[i] = -8; break;
                case 9: original[i] = -9; break;
            }
	}
	
		else {
			original[i] = std::abs(original[i]); 
			// returns the absolute value of the number
		}
	}
}

std::ostream& operator<<(std::ostream &out, const BigInteger &ans){
	
	out << ans.integer(); 
	return out; // returns the string
}

