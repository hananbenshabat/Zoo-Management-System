#ifndef __BAT_H
#define __BAT_H
#include "Mammal.h"
#include "Canfly.h"

const int BAT = 2;
class Bat : public Mammal , public Canfly
{
public:
	Bat(int sn, const string& nm, float h, float w) : Mammal(sn, nm, h, w, 2), Canfly(10){}
	Bat(Bat&& other) : Mammal(other), Canfly(other) {}
	Bat(const Bat& other) : Mammal(other), Canfly(other) {}

	void fly() const;
	void makeSound() const;
	void eat();
	int getAnimalType()const { return BAT; }
	virtual Animal* clone() const override { return new Bat(*this); }
	const Bat& operator++();
	friend ostream& operator<< (ostream& os, const Bat& bat);
};

#endif 