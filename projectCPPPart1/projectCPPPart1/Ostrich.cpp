#include "Ostrich.h"

void Ostrich::makeSound() const
{
	cout << "Ostrich " << name << " is making noise.";
}

void Ostrich::eat()
{
	cout << "Ostrich " << name << " is eating.";
	this->operator++();
}

const Ostrich& Ostrich::operator++()
{
	weight += (float)0.5;
	return *this;
}

ostream& operator<<(ostream& os, const Ostrich& ost)
{
	os << (Animal&)ost;
	return os;
}