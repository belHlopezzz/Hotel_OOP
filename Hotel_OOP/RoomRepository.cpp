#include "RoomRepository.h"

RoomRepository::RoomRepository()
{
	m_rooms.reserve(40);
}

RoomRepository& RoomRepository::Get()
{
	static RoomRepository instance;
	return instance;
}

std::vector<Room>& RoomRepository::GetRooms()
{
	return Get().m_rooms;
}
