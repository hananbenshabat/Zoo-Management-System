#include "Zoo.h"

Zoo* Zoo::theOnlyZoo = 0;

Zoo::Zoo(const string& name, Address& add): address(add)
{
	this->name = name;
	this->employees = List<Employee*>();
}

Zoo* Zoo::getInstance(const string& name, Address& add)
{
	if (theOnlyZoo == 0)
		theOnlyZoo = new Zoo(name, add);

	return theOnlyZoo;
}

Zoo::Zoo(const Zoo& other)
{
	this->name = other.name;
	this->cages = other.cages;
	this->employees = other.employees;
}

Zoo::~Zoo()
{
	cout << "~Zoo" << endl;
}

void Zoo::addAnimal(Animal& animal)
{
	for (auto it = cages.begin(); it != cages.end(); ++it)
	{

		if ((*it)->getType() == animal.getAnimalType())
		{
			if ((*it)->getAnimalsVec().size() < 5)
			{
				(*it)->addAnimal(&animal);
				return;
			}
			cout << "Cage is full please open new cage!";
		}
	}

}

void Zoo::removeAnimal(int serialNumber)
{
	auto start = cages.begin(), end = cages.end();
	while (start != end)
	{
		(*start)->removeAnimal(serialNumber);
		start++;
	}
}

void Zoo::addEmployee(Employee& employee)
{
	employees.insertEnd(&employee);
}

void Zoo::removeEmployee(int employeeNumber)
{
	ListNode <Employee*>* curr = this->employees.startPtr;

	while (curr != nullptr)
	{
		if (curr->getData()->getEmployeeNumber() == employeeNumber)
		{
			this->employees.removeNode(curr->getData());
			return;
		}
		curr = curr->nextPtr;
	}
	return;
}

void Zoo::show() const
{
	showAllEmployees();
	showAllAnimals();
}

void Zoo::addCage(int type)
{
	for (auto itr = cages.begin(); itr != cages.end(); ++itr)
	{
		if ((*itr)->getType() == type)
		{
			if ((*itr)->getAnimalsVec().size() == 5)
			{
				cages.push_back(new Cage(type));
				return;
			}
			cout << "semi full cages must be filled before opening a new cage!" << endl;
			return;
		}
	}
	cages.push_back(new Cage(type));	
}

void Zoo::showAllAnimals() const
{
	cout << "All animals in the ZOO:\n\n";
	int i = 0;
	for (auto itr = cages.begin(); itr != cages.end(); ++itr, i++)
	{
		cout << "cage number #" << i + 1 << ":" << **itr <<"\n";
	}
}

void Zoo::showAllEmployees() const
{
	ListNode <Employee*>* curr = this->employees.startPtr;
	while (curr != this->employees.endPtr)
	{
		Employee* toPrint = curr->getData();
		cout <<"#" << toPrint->getEmployeeNumber() <<" Name: "<< toPrint->getName() <<" Role: " << toPrint->getRole() << endl;
		curr = curr->nextPtr;
	}
	//last employee
	Employee* toPrint = curr->getData();
	cout << "#" << toPrint->getEmployeeNumber() << " Name: " << toPrint->getName() << " Role: " << toPrint->getRole() << endl <<"\n";
	return;
}

void Zoo::feedAllAnimals()
{

	for (auto it = cages.begin(); it != cages.end(); ++it)
	{
		int i, size = (*it)->getAnimalsCount();
		for (i = 0; i < size; i++)
		{
			(*it)->getAnimalsVec()[i]->eat();
			cout << endl;
		}
	}

}
