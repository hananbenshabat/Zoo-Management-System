#include "Bat.h"

void Bat::fly()const
{
	cout << "Bat " << name << " is flying.";
}

void Bat::makeSound() const
{
	cout << "Bat " << name << " is making noise.";
}

void Bat::eat()
{
	cout << "Bat " << name << " is eating.";
	this->operator++();
}

const Bat& Bat::operator++()
{
	weight = weight + 0.1;
	return *this;
}

ostream& operator<<(ostream& os, const Bat& bat)
{
	os << (Animal&)bat;
	return os;
}