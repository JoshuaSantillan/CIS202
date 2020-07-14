#include<iostream>
#include<vector>
#include<string>
#include "animal.h"
#include"insect.h"
#include"mammal.h"
#include"reptile.h"

int main(){
	std::vector<Animal*> zoo; 
	
	zoo.push_back (new Mammal());
	zoo.push_back (new Insect());
	zoo.push_back (new Reptile());
	
	for(Animal* animal : zoo){
		animal->eat();
	}


	return 0;
}
