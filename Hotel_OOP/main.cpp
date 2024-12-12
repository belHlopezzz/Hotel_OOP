#include "Human.h"
#include "Employee.h"
#include "Guest.h"
#include "Room.h"
#include <iostream>
#include <vector>
#include <ctime>
#include "Cleaner.h"
#include "Hotel.h"
#include "Manager.h"
#include <windows.h>
#include "C:\name-generator-release-0.2\dasmig\namegen.hpp"
#include "RegistrationBook.h"


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

	SetConsoleOutputCP(CP_UTF8);
	srand(time(NULL));
	/*Human human("Ignat", "Pikta");
	std::cout << human.GetFirstName();

	Employee employee("Ignat", "Pikta", 1000);
	Employee employee2("Kirill", "Derygin", 1000);
	std::cout << employee.GetID();
	std::cout << employee2.GetID();

	Guest guest1("Ignat", "Pikta", 1000.0f);<
	Guest guest2("Ignat2", "Pikta", 1000.0f);
	std::cout << std::endl;
	std::cout << guest1.GetBalance() << guest1.GetID();
	std::cout << guest2.GetBalance() << guest2.GetID();*/
	
	//Room room(3, false);
	//std::cout << room.GetPricePerNight();

	//std::vector<Room> rooms;
	//rooms.reserve(10); // differ from resize, since resize will create default objects in a vector, but resize only allocates enough memory for reserving these objects
	////i basically did this to miminize the amount of copies 
	//for (int i = 0; i < 10; i++)
	//{
	//	try
	//	{
	//		rooms.emplace_back(rand() % 5, rand() % 2);
	//	}
	//	catch (const std::invalid_argument& exception)
	//	{
	//		std::cerr << exception.what();
	//	}
	//}
	//for (const auto& room : rooms)
	//{
	//	std::cout << room.GetPricePerNight() << std::endl;
	//}

	/*Cleaner cleaner("Rinat", "Pikta");
	std::cout << cleaner.GetNumberOfCleanedRooms() << std::endl;

	Room room(3, false);
	std::cout << room.GetIsClean() << std::endl;

	Guest guest("Ignat", "Pikta", 3000.0f);
	guest.FoulRoom(room);
	std::cout << room.GetIsClean() << std::endl;

	cleaner.CleanRoom(room);
	std::cout << room.GetIsClean() << std::endl;
	std::cout << cleaner.GetNumberOfCleanedRooms() << std::endl;*/

	/*std::vector<Room> rooms;
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
	employees.reserve(2);

	Cleaner cleaner("LJlkjl", "lalkjf");
	Manager manager("lkjalkj", "lajflajk");

	employees.emplace_back(cleaner);
	employees.emplace_back(manager);

	Hotel hotel(4, "Eleon", rooms, employees);*/

	//hotel.DisplayEmployeeInfo();
	// 
	//Manager manager2(RandomFirstName(), RandomSecondName());
	//Cleaner cleaner2(RandomFirstName(), RandomSecondName());
	//hotel.AddEmployee(manager2);
	//hotel.AddEmployee(cleaner2);
	//hotel.DisplayEmployeeInfo();

	//try
	//{
	//	hotel.DeleteEmployee(9);
	//}
	//catch (const std::runtime_error& exception)
	//{
	//	std::cerr << exception.what();
	//}
	//hotel.DisplayEmployeeInfo();

	/*hotel.DisplayRoomInfo();

	Guest guest(RandomFirstName(), RandomSecondName(), RandomBalance());
	guest.FoulRoom(9, hotel);

	hotel.DisplayRoomInfo();*/
	
	Hotel hotel(3, "Bly");
	hotel.AddRoom();

	RegistrationBook regBook;

	hotel.AddRoom();

}