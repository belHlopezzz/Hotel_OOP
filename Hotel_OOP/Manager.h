#pragma once
#include "Employee.h"
#include "Hotel.h"
#include <vector>

class Manager : public Employee
{
private:
	std::vector<Employee> m_subordinates;

public:
	Manager(const std::string& firstName, const std::string& secondName);
	// add hotel reference, and then use hotel 
	// method to gain a vector of non-manager employees
};

