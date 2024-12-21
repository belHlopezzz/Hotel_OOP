#pragma once
#include "Service.h"
#include "Room.h"

class RoomCleaning : public Service
{
private:
	Room* m_room;

public:
    RoomCleaning(Room* room);

    void ExecuteService() override;

    Room* GetRoom() const;
};

