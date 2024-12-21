#include "Human.h"
#include "Employee.h"
#include "Guest.h"
#include "Room.h"
#include "Cleaner.h"
#include "Hotel.h"
#include "Manager.h"
#include "Administrator.h"
#include "Review.h"
#include "MenuItem.h"
#include "Menu.h"
#include "Restaurant.h"
#include "Service.h"
#include "RoomCleaning.h"
#include "FoodOrder.h"
#include "C:\name-generator-release-0.2\dasmig\namegen.hpp"
#include <iostream>
#include <vector>
#include <ctime>

using ng = dasmig::ng;

std::string RandomFirstName()
{
	std::wstring firstNamew = ng::instance().get_name(ng::gender::m, ng::culture::russian);
	std::string firstName(firstNamew.begin(), firstNamew.end());
	return firstName;
}

std::string RandomSecondName()
{
	std::wstring secondNamew = ng::instance().get_surname(ng::culture::russian);
	std::string secondName(secondNamew.begin(), secondNamew.end());
	return secondName;
}

float RandomBalance()
{
	return float(rand() % 10000 + 100);
}


int main()
{
	ng::instance().load("C:\\name-generator-release-0.2\\resources");
	srand(time(NULL));

	std::vector<Room> rooms;
	rooms.reserve(10);

	for (size_t i = 0; i < 10; i++)
	{
		try
		{
			rooms.emplace_back(rand() % 5, rand() % 2);
		}
		catch (const std::invalid_argument& exception)
		{
			std::cerr << exception.what();
		}
	}

	std::vector<Employee> employees;
	employees.reserve(10);

	Cleaner cleaner(RandomFirstName(), RandomSecondName());
	Manager manager(RandomFirstName(), RandomSecondName());
	Administrator admin(RandomFirstName(), RandomSecondName());
	employees.emplace_back(cleaner);
	employees.emplace_back(manager);
	employees.emplace_back(admin);

	Hotel hotel(4, "Eleon", rooms, employees);
	//hotel.DisplayRoomInfo();
	Cleaner cleaner2(RandomFirstName(), RandomSecondName());
	Cleaner cleane3(RandomFirstName(), RandomSecondName());
	Administrator admin2(RandomFirstName(), RandomSecondName());
	hotel.AddEmployee(cleaner2);
	hotel.AddEmployee(cleane3);
	hotel.AddEmployee(admin2);
	/*hotel.DisplayEmployeeInfo();*/

	Guest guest(RandomFirstName(), RandomSecondName(), 300.0f);
	std::cout << guest.GetKeyFromRoom() << std::endl;
	try
	{
		guest.BookRoom(3, false, 3, admin, hotel);
	}
	catch (const std::runtime_error& exception)
	{
		std::cerr << exception.what();
	}
		Hotel hotel3(1, "ljfld");
		hotel3.AddRoom(2, false);

		Room room5(2, false);
		std::cout << room5.GetRoomNumber();
}