#include "Manager.h"

Manager::Manager(const std::string& firstName, const std::string& secondName)
	:Employee(firstName, secondName, 1500.0f, "Manager") { }

void Manager::HireEmployee(Hotel& hotel, Employee& employee)
{
    hotel.AddEmployee(employee);
    std::cout << "Employee " << employee.GetFirstName() << " " << employee.GetSecondName() << " has been hired.\n";
}

void Manager::FireEmployee(Hotel& hotel, int employeeID)
{
    hotel.DeleteEmployee(employeeID);
    std::cout << "Employee with ID " << employeeID << " has been fired.\n";
}
