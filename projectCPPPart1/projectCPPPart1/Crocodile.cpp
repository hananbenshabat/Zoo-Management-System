#include "Crocodile.h"

Crocodile::Crocodile(int sn, const string& nme, float h, float w) :Reptile(sn, nme, h, w, 5), CanSwin(20){}

Crocodile::Crocodile(const Crocodile& other): Reptile(other), CanSwin(other){}

Crocodile::Crocodile(Crocodile&& other): Reptile(other), CanSwin(other){}

Crocodile::~Crocodile(){}

const Crocodile& Crocodile::operator++()
{
	weight = weight + 1.2;
	return *this;
}

void Crocodile::swim() const
{
	cout << "Crocodile " << name << " is swimming.";
}

void Crocodile::makeSound() const
{
	cout << "Crocodile " << name << " is making sound.";
}

void Crocodile::eat()
{

	cout << "Crocodile " << name << " is eating.";
	this->operator++();
}

ostream& operator<<(ostream& os, const Crocodile& croc)
{
	os << "Type Crocodile:" << (Animal&)croc ;
	return os;
}
