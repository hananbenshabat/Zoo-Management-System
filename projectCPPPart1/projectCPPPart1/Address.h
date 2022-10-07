#ifndef __ADDRESS_H
#define __ADDRESS_H
#include <iostream>
#include <string.h>
using namespace std;
class Address
{
protected:
	string street;
	int number;
	string city;
public:
	Address() : Address(" ", 1, " ") {}; //need to change
	Address(const string& street, int num, const string& city);
	Address(Address& other);
	Address(Address&& other);
	~Address();
	friend ostream& operator<<(ostream& os, const Address& address);



};
#endif
