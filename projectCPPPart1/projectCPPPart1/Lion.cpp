#include "Lion.h"
#include <iostream>
using namespace std;

Lion::~Lion()
{
}

void Lion::makeSound() const
{
	cout << "Lion " << name << " is Roaring.";
}

void Lion::eat()
{
	cout << "Lion " << name << " is eating.";
	this->operator++();
}

const Lion& Lion::operator++()
{
	weight = weight + 0.8;
	return *this;
}

ostream& operator<<(ostream& os, const Lion& leo)
{
	os << (Animal&)leo <<"type: Lion";
	return os;
}