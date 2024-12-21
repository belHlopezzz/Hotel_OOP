#include "Administrator.h"
#include "Guest.h"

Administrator::Administrator(const std::string& firstName, const std::string& secondName)
	:Employee(firstName, secondName, 1000.0f, "Administrator") {}

void Administrator::BedGuest(Guest& guest, int numberOfBeds, int numberOfNights, bool isVIP, Hotel& hotel)
{
	for (auto& room : hotel.GetRooms())
	{
		if (room.GetIsAvailable() && room.GetNumberOfBeds() == numberOfBeds && room.GetIsVIP() == isVIP)
		{
			if (guest.GetBalance() < room.GetPricePerNight() * (float)numberOfNights)
				throw std::runtime_error("Warning: Guest " + guest.GetFirstName() + " can't afford it.\n\n");
			guest.SetBalance(guest.GetBalance() - room.GetPricePerNight() * (float)numberOfNights);
			guest.SetKeyFromRoom(room.GetRoomNumber());
			hotel.UpdateRoomAvailability(room.GetRoomNumber(), false);
			return;
		}
	}
	
	throw std::runtime_error("Warning: There are no availble rooms.\n\n");
}
