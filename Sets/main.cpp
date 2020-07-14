/*
  Name: Joshua Santillan
  File: main.cpp
  Description: Finding prime numbers using seize of erothese
  Date: 4/20/2019
*/
#include <iostream>
#include <cmath>
#include <set>

void primes(int n);
int main()
{
  std::cout << "Pick a number to find the prime numbers: ";
  int x;
  std::cin >> x;
	
  primes(x);

	return 0;
}
void primes(int n)
{

	std::set<int> s;
	std::set<int>::iterator pos = s.begin();
	for (int i = 2; i <= n; i++) { // start at 2 for prime numbers 
		s.insert(i); // pushing number[i] into the set
		if (pos != s.end())
			pos++;
	}

	pos = s.begin();
	while (pos != s.end()) {
		int current = *pos++;
		int erase = pow(current,2);
		while (erase <= n) {
			s.erase(erase);
			erase += current;
		}
	}

  // prints out the formatted set while pos isnt at the end. 
	pos = s.begin();
	while (pos != s.end()) {
		std::cout << *pos << std::endl;
		pos++;
	}
std::cout << std::endl;
}
