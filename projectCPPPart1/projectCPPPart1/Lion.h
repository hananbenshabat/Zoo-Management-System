
#ifndef __LION_H
#define __LION_H

#include "Mammal.h"
#include <stdio.h>
const int LEGS = 4;
const int LION = 0;

class Lion :public Mammal
{
	public:
	Lion(int s, const string& name, float h, float w) : Mammal(s, name, h, w, LEGS){}
	Lion(const Lion& other) : Mammal(other) {}
	Lion(Lion&& other) : Mammal(other) {}
	~Lion();

	void makeSound() const ;
	void eat();
	int getAnimalType()const { return LION; }
	virtual Animal* clone() const override { return new Lion(*this); }
	const Lion& operator++();
	friend ostream& operator<< (ostream& os, const Lion& leo);
};

#endif 