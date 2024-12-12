#pragma once
#include "Room.h"
#include <vector>

// Singleton
class RoomRepository
{
private:
	RoomRepository();

private:
	std::vector<Room> m_rooms;

public:
	RoomRepository(const RoomRepository&) = delete;

	static RoomRepository& Get();

	static std::vector<Room>& GetRooms();
};

