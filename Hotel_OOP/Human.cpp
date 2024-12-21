#include "Human.h"

Human::Human(const std::string& firstName, const std::string& secondName)
	:m_firstName(firstName), m_secondName(secondName) {}

std::string Human::GetFirstName() const
{
	return m_firstName;
}

std::string Human::GetSecondName() const
{
	return m_secondName;
}
