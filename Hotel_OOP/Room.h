#pragma once
#include <string>
#include <stdexcept>
#include <iostream>

class Room
{
protected:
	float m_pricePerNight;
	int m_roomNumber;
	static int m_roomNumberBuffer;
	int m_numberOfBeds;
	bool m_isVIP;
	bool m_isClean; 
	bool m_isAvailable;

private:
	float CalculatePricePerNight();

public:
	Room(const int& numberOfBeds, const bool& isVIP);

	int GetRoomNumber() const;
	float GetPricePerNight() const;
	bool GetIsVIP() const;
	int GetNumberOfBeds() const;
	bool GetIsClean() const;
	bool GetIsAvailable() const;

	void SetIsClean(const bool& isClean);
	void SetIsAvailble(const bool& isAvailable);
	void SetRoomNumber(const int& roomNumber);

	~Room();
};

