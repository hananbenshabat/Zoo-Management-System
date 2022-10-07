#pragma warning(disable: 4996)
#ifndef __ANIMAL_H
#define __ANIMAL_H

#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

class Animal
{
protected:
	int serialNumber;
	string name;
	float height;
	float weight;

	Animal(int sn, const string& nme, float height1, float weight1);
	
	
public:
	
	const Animal& operator=(const Animal& other);
	Animal(const Animal& other);
	virtual ~Animal();
	virtual void eat()  = 0;
	virtual void makeSound() const = 0;
	void setHeight(float h){} //consider boolean or exception
	void setWeight(float w){} //consider boolean or exception
	void setName(const string& name);
	const string& getName() const { return name; }
	float getHeight() const { return height; }
	float getWeight() const { return weight; }
	int getSerialNum()const { return serialNumber;}
	virtual Animal* clone() const = 0;
	virtual int getAnimalType()const = 0;
	friend ostream& operator<< (ostream& os, const Animal& animal);
	

};

#endif 