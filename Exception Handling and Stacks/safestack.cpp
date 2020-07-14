#include"safestack.h"
/*
	Name: Joshua Santillan
	Filename: safestack.cpp
	Date: apr 23 19
	Email: santj96@gmail.com
	description: modify stack class to andle an exception in which it errors when trying to remove from an empty stack
*/
SafeStack::SafeStack(){
	
}

void SafeStack::pop(){
	
	if(!m_stack.empty())
		m_stack.pop();
	else
		throw SafeStackErr("Error: Stack is empty\n");

}

void SafeStack::top(){
	
	std::string print = m_stack.top();
	if(!m_stack.empty()){
		std::cout << print << std::endl; 
	}
	else	
		throw SafeStackErr("Error: Stack is empty\n");


}
void SafeStack::push(const std::string &p){
	
		m_stack.push(p);
}

bool SafeStack::empty(){
	
	return m_stack.empty();
}

