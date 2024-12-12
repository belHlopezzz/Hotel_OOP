#pragma once
#include "Human.h"
#include "Room.h"
#include "Hotel.h"
#include "Administrator.h"

class Guest: public Human 
{
private:
	float m_balance;
	int m_ID;
	static int m_bufferID;
	

public:
	Guest(const std::string& fisrtName, const std::string& secondName, const float& balance);

	int GetID() const;
	float GetBalance() const;

	//void FoulRoom(const int& roomNumber, Hotel& hotel);

	/*void BookRoom(const int& numberOfBeds, const bool& isVIP, Administrator& admin);*/

	~Guest();
};



