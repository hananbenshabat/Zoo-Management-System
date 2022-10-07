#include "Animal.h"

Animal::Animal(int sn, const string& nme, float height1, float weight1)
{
	this->serialNumber = sn;
	this->name = nme;
	this->height = height1;
	this->weight = weight1;
}

Animal::Animal(const Animal& other)
{
	*this = other;
}

Animal::~Animal()
{
	cout << "~Animal" << endl;
}

const Animal& Animal::operator=(const Animal& other)
{
	this->setName(other.getName());
	this->serialNumber = other.getSerialNum();
	this->height = other.getHeight();
	this->weight = other.getWeight();
	return *this;
}

void Animal::setName(const string& name)
{
	this->name = name;
}

ostream& operator<<(ostream& os, const Animal& animal)
{
	os << "Serial Num: " << animal.serialNumber << ", Name: " << animal.name << ", Weight: " << animal.weight
		<< ", Height: " << animal.height << endl;
	return os;
}