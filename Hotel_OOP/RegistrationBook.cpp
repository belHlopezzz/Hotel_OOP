#include "RegistrationBook.h"

RegistrationBook::RegistrationBook()
{
	std::vector<Room>& rooms = RoomRepository::GetRooms();
	rooms.emplace_back(3, true);
}
