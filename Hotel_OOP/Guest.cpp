#include "Guest.h"

int Guest::m_bufferID = 1;

Guest::Guest(const std::string& firstName, const std::string& secondName, const float& balance)
	:Human(firstName, secondName), m_balance(balance), m_ID(m_bufferID++) {}

int Guest::GetID() const
{
	return m_ID;
}

float Guest::GetBalance() const
{
	return m_balance;
}

//void Guest::FoulRoom(const int& roomNumber, Hotel& hotel)
//{
//	try
//	{
//		hotel.MakeRoomDirty(roomNumber);
//	}
//	catch (const std::runtime_error& exception)
//	{
//		std::cerr << exception.what();
//	}
//}

//void Guest::BookRoom(const int& numberOfBeds, const bool& isVIP, Administrator& admin)
//{
//	try
//	{
//		admin.BedGuest(*this, numberOfBeds, isVIP);
//	}
//	catch (const std::exception& exception)
//	{
//		std::cerr << exception.what();
//	}
//}

Guest::~Guest()
{
	m_bufferID--;
}



