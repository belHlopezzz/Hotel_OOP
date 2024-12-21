#pragma once

#include "Human.h"

class Employee : public Human
{	
protected:
	float m_salary;
	std::string m_position;
	int m_ID;
	static int m_bufferID;

public:
	Employee(const std::string& firstName, const std::string& secondName, float salary, 
		const std::string& position);

	int GetID() const;
	float GetSalary() const;
	std::string GetPosition() const;

	void SetID(int ID);

	~Employee();
};

