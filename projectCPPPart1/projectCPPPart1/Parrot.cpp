#include "Parrot.h"

Parrot::~Parrot()
{
}

void Parrot::fly()const
{
	cout << "Parrot " << name << " is flying.";
}

void Parrot::makeSound() const
{
	cout << "Parrot " << name << " is making noise.";
}

void Parrot::eat()
{
	cout << "Parrot " << name << " is eating.";
	this->operator++();
}

const Parrot& Parrot::operator++()
{
	this->weight = this->weight + 0.3;
	return *this;
}

ostream& operator<<(ostream& os, const Parrot& pat)
{
	os << (Animal&)pat;
	return os;
}