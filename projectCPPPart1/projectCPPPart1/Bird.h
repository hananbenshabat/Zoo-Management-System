#pragma warning(disable: 4996)
#ifndef __BIRD_H
#define __BIRD_H
#include "Animal.h"
#include <stdio.h>
#include <string.h>
class Bird : public Animal
{
private:
	string colorOfFeathers;
	float sizeOfbeak;

public:
	Bird(int sn, const string& nme, float h, float w,const string& cof, float sob) : Animal(sn, nme, h, w)
	{
		sizeOfbeak = sob;
		colorOfFeathers = cof;
	}

	//~Bird(); 

	const string& getColorOfFeathers() const { return colorOfFeathers; }
	float getSizeOfBeak() const { return sizeOfbeak; }


};
#endif

