#pragma once
#include "Employee.h"
#include "Room.h"
class Cleaner : public Employee
{
private:
	int m_numberOfCleandRooms;
public:
	Cleaner(const std::string& firstName, const std::string& secondName);

	int GetNumberOfCleanedRooms() const;

	void CleanRoom(Room& room);
};

