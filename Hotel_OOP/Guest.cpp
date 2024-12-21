#include "Guest.h"
#include "Administrator.h"
#include "Review.h"

int Guest::m_bufferID = 1;

Guest::Guest(const std::string& firstName, const std::string& secondName, float balance)
	:Human(firstName, secondName), m_balance(balance), m_ID(m_bufferID++), m_keyFromRoom(0) {}

int Guest::GetID() const
{
	return m_ID;
}

float Guest::GetBalance() const
{
	return m_balance;
}

int Guest::GetKeyFromRoom() const
{
	return m_keyFromRoom;
}

void Guest::SetKeyFromRoom(int keyFromRoom)
{
	m_keyFromRoom = keyFromRoom;
}

void Guest::SetBalance(float balance)
{
	m_balance = balance;
}

void Guest::FoulRoom(Hotel& hotel)
{
	try
	{
		hotel.MakeRoomDirty(m_keyFromRoom);
	}
	catch (const std::runtime_error& exception)
	{
		std::cerr << exception.what();
	}
}

void Guest::OrderService(Service* service)
{
	if (m_balance >= service->GetPrice()) {
		std::cout << "Service ordered: " << service->GetServiceName() << " for "
			<< service->GetPrice() << " USD." << std::endl;
		m_balance -= service->GetPrice();
		service->ExecuteService();
	}
	else {
		std::cout << "Insufficient balance to order: " << service->GetServiceName() << std::endl;
	}
}

void Guest::BookRoom(int numberOfBeds, bool isVIP, int numberOfNights, Administrator& admin, Hotel& hotel)
{
	try
	{
		admin.BedGuest(*this, numberOfBeds, numberOfNights, isVIP, hotel);
	}
	catch (const std::runtime_error& exception)
	{
		std::cerr << exception.what();
	}
}

Review Guest::LeaveReview(int rating, const std::string& comment, const std::string& date)
{
	return Review(date, rating, comment, this);
}


Guest::~Guest()
{
	m_bufferID--;
}



