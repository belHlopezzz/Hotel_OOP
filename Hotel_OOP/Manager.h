#pragma once
#include "Employee.h"
#include <vector>
#include "Hotel.h"

class Manager : public Employee
{
public:
	Manager(const std::string& firstName, const std::string& secondName);
	

	void HireEmployee(Hotel& hotel, Employee& employee);

	void FireEmployee(Hotel& hotel, int employeeID);
};

