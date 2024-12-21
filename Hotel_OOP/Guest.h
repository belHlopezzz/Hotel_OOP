#pragma once
#include "Human.h"
#include "Hotel.h"
#include "Service.h"

class Administrator;
class Review;

class Guest: public Human 
{
private:
	float m_balance;
	int m_ID;
	static int m_bufferID;
	int m_keyFromRoom;
	

public:
	Guest(const std::string& fisrtName, const std::string& secondName, float balance);

	int GetID() const;
	float GetBalance() const;
	int GetKeyFromRoom() const;

	void SetKeyFromRoom(int keyFromRoom);
	void SetBalance(float balance);

	void FoulRoom(Hotel& hotel);

	void OrderService(Service* service);

	void BookRoom(int numberOfBeds, bool isVIP, int numberOfNights, Administrator& admin, Hotel& hotel);

	Review LeaveReview(int rating, const std::string& comment, const std::string& date);

	~Guest();
};



