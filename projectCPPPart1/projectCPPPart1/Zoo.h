#pragma warning(disable: 4996)
#ifndef __ZOO_H
#define __ZOO_H
#include "Address.h"
#include "Animal.h"
#include "Cage.h"
#include "Employee.h"
#include "List.h"


class Zoo
{
private:
	string name;
	vector<Cage*> cages;
	List<Employee*> employees;
	Address address;
	static Zoo* theOnlyZoo;
	Zoo(const string& name, Address& add);

public:

	static Zoo* getInstance(const string& name, Address& add);
	Zoo(const Zoo& other);
	Zoo(Zoo&& other);
	~Zoo();

	void addAnimal(Animal& animal);
	void removeAnimal(int serialNumber);
	void addEmployee(Employee& employee);
	void removeEmployee(int employeeNumber);
	void show() const ;
	void addCage(int type);
	void showAllAnimals()const;
	void showAllEmployees()const;
	void feedAllAnimals();
	Cage& operator[](int index) { return *cages[index]; }
};

#endif 