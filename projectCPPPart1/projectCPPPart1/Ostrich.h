#ifndef __OSTRICH_H
#define __OSTRICH_H
#include <ostream>
#include "Bird.h"

const int OSTRICH = 3;
class Ostrich: public Bird
{

public:
	Ostrich(int sn, const string& nme, float h, float w, const string& color) : Bird(sn, nme, h, w, color, h/w) {}
	Ostrich(const Ostrich& other) : Bird(other) {}
	Ostrich(Ostrich&& other): Bird(other) {}
	//~Ostrich();

	void makeSound() const override;
	void eat() override;
	int getAnimalType()const { return OSTRICH; }
	virtual Animal* clone() const override { return new Ostrich(*this); }
	friend ostream& operator<< (ostream& os, const Ostrich& ost);
	const Ostrich& operator++();

};
#endif

