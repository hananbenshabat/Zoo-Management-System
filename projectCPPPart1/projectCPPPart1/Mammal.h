#ifndef __MAMMAL_H
#define __MAMMAL_H
#include "Animal.h"

class Mammal :public Animal
{
protected:
	
	int numberOfLegs=0;
	Mammal(int sn, const string& nm ,float h , float w ,int nol) : Animal(sn, nm, h,w) {
		
		numberOfLegs = nol;
	}

	
public:
	


};

#endif 