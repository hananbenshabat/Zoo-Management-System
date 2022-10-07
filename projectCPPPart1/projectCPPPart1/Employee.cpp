#include "Employee.h"

Employee::Employee(Employee& other)
{
	*this = other;
}

const Employee& Employee::operator=(const Employee& other)
{
	this->employeeNumber = other.getEmployeeNumber();
	this->setName(other.getName());
	this->setRole(other.getRole());
	return *this;
}

void Employee::setName(const string& name)
{
	this->name = name;
}

void Employee::setRole(const string& role)
{
	this->role = role;
}

ostream& operator<<(ostream& os, const Employee& emp)
{
	os << "Employee ID: " << emp.employeeNumber << ", Name: " << emp.name << " ,Role: " << emp.role << endl;
	return os;
}