#pragma once
#include "Employee.h"
#include "Room.h"
#include "Hotel.h"

class Guest;

class Administrator : public Employee
{
public:
	Administrator(const std::string& firstName, const std::string& secondName);

	void BedGuest(Guest& guest, int numberOfBeds, int numberOfNights, bool isVIP, Hotel& hotel);
};

