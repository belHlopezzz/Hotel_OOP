#include "Employee.h"

int Employee::m_bufferID = 1;

Employee::Employee(const std::string& firstName, const std::string& secondName, float salary, 
	const std::string& position)
	:Human(firstName, secondName), m_salary(salary), m_position(position), m_ID(m_bufferID++) {}

int Employee::GetID() const
{
	return m_ID;
}

float Employee::GetSalary() const
{
	return m_salary;
}

std::string Employee::GetPosition() const
{
	return m_position;
}

void Employee::SetID(int ID)
{
	m_ID = ID;
}

Employee::~Employee()
{
	m_bufferID--;
}


