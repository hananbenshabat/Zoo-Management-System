#define _CRT_SECURE_NO_WARNINGS
#include "Address.h"

Address::Address(const string& street, int num, const string& city)
{
	this->street = street;
	this->number = num;
	this->city = city;
}

Address::Address(Address& other)
{
	this->street = other.street;
	this->number = other.number;
	this->city = other.city;
}

Address::Address(Address&& other)
{
	this->street = other.street;
	this->city = other.city;
	this->number = other.number;
}

Address::~Address(){}

ostream& operator<<(ostream& os, const Address& address)
{
	os << "Address: " << address.number << ", " << address.street << ", " << address.city << endl;
	return os;
}
