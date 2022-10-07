#include "Cage.h"

Cage::Cage(int type): cageType(type){}

Cage::Cage(const Cage& other)
{
	this->cageType = other.cageType;
	this->animals = other.animals;
}

Cage::Cage(Cage&& other)
{
	this->animals = other.animals;
	this->cageType = other.getType();
}

Cage::~Cage(){}

void Cage::addAnimal(Animal* animal)
{
	this->animals.push_back(animal);
}

void Cage::removeAnimal(int sn)
{
	std::vector<Animal*>::iterator itr;
	for (itr = animals.begin(); itr != animals.end(); itr++)
	{
		if ((*itr)->getSerialNum() == sn)
		{
			animals.erase(itr);
		}

	}	
}

string Cage::getStringType(int type) const
{
	if (type == 0)
		return "Lion";
	else if (type == 1)
		return "Crocodile";
	else if (type == 2)
		return "Bat";
	else if (type == 3)
		return "Ostrich";
	else if (type == 4)
		return "Parrot";
	
	return "Animal";
}

const Cage& Cage::operator+=(const Cage& other)
{
	
	for (auto itr = other.animals.begin(); itr != other.animals.end(); itr++)
	{
		addAnimal(*itr);
	}
	return *this;
}

const Cage& Cage::operator+=(Animal& other)
{
	addAnimal(&other);
	return *this;
}

ostream& operator<<(ostream& os, const Cage& cg)
{
	int type = cg.getType();
	string typeString = cg.getStringType(type);
	
	int count = cg.getAnimalsCount();
	os << " Animals in Cage is:  " << count << endl;
	os << "Cage Animal Type : " << typeString << endl;

	for (int i = 0; i < count; i++)
		os << "#"<<i+1 <<" "<< *(cg.animals[i]) << "\n";

	return os;
}
