#include "RoomCleaning.h"

RoomCleaning::RoomCleaning(Room* room)
    : Service("Room Cleaning", room->GetIsVIP() ? 30.0f : 20.0f), m_room(room) {}

void RoomCleaning::ExecuteService()
{
    if (m_room) {
        m_room->SetIsClean(true);
        std::cout << "Room " << m_room->GetRoomNumber() << " has been cleaned." << std::endl;
    }
    else {
        std::cerr << "Error: No room assigned for cleaning." << std::endl;
    }
}

Room* RoomCleaning::GetRoom() const
{
    return m_room;
}
