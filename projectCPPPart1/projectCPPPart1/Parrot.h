#ifndef __PARROT_H
#define __PARROT_H
#include "Bird.h"
#include "Canfly.h"

const int PARROT = 4;
class Parrot : public Bird , public Canfly
{
public :
	Parrot(int sn, const string& nme, float h, float w, const string& cof, float sob, int spOf)
		: Bird(sn, nme, h, w, cof, sob), Canfly(spOf){}
	Parrot(const Parrot& other) : Bird(other), Canfly(other) {}
	Parrot(Parrot&& other):Bird(other), Canfly(other) {}
	~Parrot();

	void fly() const override;
	void makeSound() const override;
	void eat();
	int getAnimalType()const { return PARROT; }
	virtual Animal* clone() const override { return new Parrot(*this); }
	const Parrot& operator++();
	friend ostream& operator<< (ostream& os, const Parrot& pat);
};

#endif
