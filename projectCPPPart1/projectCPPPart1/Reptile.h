#ifndef __REPTILE_H
#define __REPTILE_H
#include "Animal.h"

class Reptile :public Animal
{
private:
	float temp = 0;
public:
	
	Reptile(int sn, const string& nme, float h, float w, float tmp);
	~Reptile(); 

	void setTemp(float tmp) { temp = tmp; }
	float getTemp() const { return temp; }
	friend ostream& operator<< (ostream& os, const Reptile& rep);
};
#endif
