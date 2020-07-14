#ifndef SAFESTACK
#define SAFESTACK
/*
	Name: Joshua Santillan
	Filename: safestack.h
	Date: apr 23 19
	Email: santj96@gmail.com
	Description: safestack header
*/
#include<iostream>
#include<stack>
#include<string>
#include<cstdlib>

#define STACK_EMPTY 100
#define PUSH_ERROR 101
class SafeStack{

	public:
		SafeStack();
		void pop();
		void push(const std::string &p);
		bool empty();
		void top();
	private:
		std::stack<std::string> m_stack;

};


class SafeStackErr : public std::logic_error
{
	public:
	SafeStackErr(const char *reason) : std::logic_error(reason){
	}
};

#endif
