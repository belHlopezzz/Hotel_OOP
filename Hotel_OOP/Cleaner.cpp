#include "Cleaner.h"

Cleaner::Cleaner(const std::string& firstName, const std::string& secondName) 
	:Employee(firstName, secondName, 800.0f, "Cleaner"), m_numberOfCleandRooms(0) { }

int Cleaner::GetNumberOfCleanedRooms() const
{
	return m_numberOfCleandRooms;
}


void Cleaner::CleanRoom(Room& room)
{
	room.SetIsClean(true);
	m_numberOfCleandRooms++;
}
