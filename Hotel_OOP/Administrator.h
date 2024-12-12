#pragma once
#include "Employee.h"
#include "RegistrationBook.h"
#include "Guest.h"


class Administrator : public Employee
{
public:
	//static RegistrationBook m_registrationBook;

public:
	Administrator(const std::string& firstName, const std::string& secondName);

	//void BedGuest(Guest& guest, const int& numberOfBeds, const bool& isVIP);
};

