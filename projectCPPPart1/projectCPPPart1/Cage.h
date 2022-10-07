#ifndef __CAGE_H
#define __CAGE_H
#include "Animal.h"
#include <vector>

class Cage
{

protected:
	vector<Animal*> animals;
	int cageType;


public:
	
	Cage(int type);
	Cage(const Cage& other);
	Cage(Cage&& other);
	~Cage();

	void addAnimal(Animal* animal);
	void removeAnimal(int sn);
	int getAnimalsCount() const { return getAnimalsVec().size(); }
	int getType() const { return cageType; }
	string getStringType(int type) const;
	vector<Animal*> getAnimalsVec() const { return animals; };
	const Cage& operator+=(const Cage& other);
	const Cage& operator+=(Animal& other);
	friend ostream& operator<< (ostream& os, const Cage& cg);

	

};
#endif

