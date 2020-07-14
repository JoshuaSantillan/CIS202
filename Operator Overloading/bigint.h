/*
	Name: Joshua Santillan
	File: bigint.h
	Email: Santillanj125821@student.vvc.edu
	Description: Header file for my big int class
*/
#ifndef BIGINT_H
#define BIGINT_H

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

class BigInteger {

	public:
	
	BigInteger();
	BigInteger(const std::string &number);
	void convert(const std::string &number);
	std::vector<int> digits() const;
	std::string integer() const;

	BigInteger operator+(const BigInteger &second_number);
	BigInteger operator-(const BigInteger &second_number);
	BigInteger operator*(const BigInteger &second_number);
//	friend std::ostream& operator<<(std::ostream &out, const BigInteger &b);
	
	private:
	
	void levels(std::vector<int> &first_number, std::vector<int> &second_number);
	void power(std::string &raise, int level);
	std::vector<int> reverse(const BigInteger &sign);
	std::string m_number;
	std::vector<int> m_digit;
	template<class T>
		void change_sign(T &original);

};


	std::ostream& operator<<(std::ostream &out, const BigInteger &ans);

#endif
