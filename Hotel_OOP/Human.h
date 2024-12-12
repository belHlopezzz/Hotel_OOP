#pragma once
#include <string>

class Human
{
protected:
	std::string m_firstName;
	std::string m_secondName;
public:
	Human(const std::string& firstName, const std::string& secondName);

	std::string GetFirstName() const;
	std::string GetSecondName() const;
};
