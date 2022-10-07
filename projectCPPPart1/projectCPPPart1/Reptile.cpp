#include "Reptile.h"

Reptile::Reptile(int sn, const string& nme, float h, float w, float tmp) :
	Animal(sn, nme, h, w)
{
	this->setTemp(tmp);
}

Reptile::~Reptile()
{

}

ostream& operator<< (ostream& os, const Reptile& rep)
{
	
	os << endl;
	return os;
}