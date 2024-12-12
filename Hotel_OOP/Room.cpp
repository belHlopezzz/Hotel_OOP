#include "Room.h"

int Room::m_roomNumberBuffer = 1;

float Room::CalculatePricePerNight()
{
    if (m_isVIP)
    {
        return float(15 * pow(m_numberOfBeds, 2) - 25 * m_numberOfBeds + 90);
    }
    return float(20 * m_numberOfBeds + 30);
}

Room::Room(const int& numberOfBeds, const bool& isVIP)
    :m_roomNumber(m_roomNumberBuffer++), m_numberOfBeds(numberOfBeds), m_isVIP(isVIP), m_isClean(true),
    m_isAvailable(true)
{  
    if (numberOfBeds < 0)
    {
        throw std::invalid_argument("Number of beds can not be negative.\n");
    }
    m_pricePerNight = CalculatePricePerNight();
}

int Room::GetRoomNumber() const
{
    return m_roomNumber;
}

float Room::GetPricePerNight() const
{
    return m_pricePerNight;
}

bool Room::GetIsVIP() const
{
    return m_isVIP;
}

int Room::GetNumberOfBeds() const
{
    return m_numberOfBeds;
}

bool Room::GetIsClean() const
{
    return m_isClean;
}

bool Room::GetIsAvailable() const
{
    return m_isAvailable;
}

void Room::SetIsClean(const bool& isClean)
{
    m_isClean = isClean;
}

void Room::SetIsAvailble(const bool& isAvailable)
{
    m_isAvailable = isAvailable;
}

void Room::SetRoomNumber(const int& roomNumber)
{
    m_roomNumber = roomNumber;
}

Room::~Room()
{
    m_roomNumberBuffer--;
}





