#pragma warning(disable: 4996)
#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;


class Employee
{
private:
	int employeeNumber;
	string name;
	string role;
	Employee(); 
public:
	Employee(int en, const string& nme,const string& rol) {
		employeeNumber = en;
		name = nme;
		role = rol;
	}

	
	Employee(Employee & other);
	const Employee& operator=(const Employee & other);
	friend ostream& operator<< (ostream& os, const Employee& emp);
	void setName(const string& name);
	void setRole(const string& role);
	const string& getName() const { return name; }
	const string& getRole() const { return role; }
	int getEmployeeNumber() const { return employeeNumber; };
	
};



#endif 
