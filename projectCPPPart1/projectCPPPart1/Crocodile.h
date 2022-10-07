#ifndef __CROCODILE_H
#define __CROCODILE_H
#include "Reptile.h"
#include "CanSwin.h"

const int CROCODILE = 1;
class Crocodile : public Reptile , public CanSwin
{
public:
	Crocodile(int sn, const string& nme, float h, float w);
	Crocodile(const Crocodile& other);
	Crocodile(Crocodile&& other);
	~Crocodile();

	void swim() const override;
	void makeSound() const override;
	void eat() override;
	int getAnimalType()const { return CROCODILE; }
	virtual Animal* clone() const override { return new Crocodile(*this); }
	const Crocodile& operator++();
	friend ostream& operator<< (ostream& os, const Crocodile& croc);
};
#endif
