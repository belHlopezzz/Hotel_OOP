#pragma once
#include "Human.h"
#include "Room.h"
#include <vector>
#include "Employee.h"
#include <string>
#include <stdexcept>
#include "RegistrationBook.h"
#include "Administrator.h"
#include "RoomRepository.h"

class Hotel
{
private:
	std::vector<Room> m_rooms;
	std::vector<Employee> m_employees;
	std::string m_name;
	int m_numberOfStars;

public:
	Hotel(const int& numberOfStars, const std::string& name, const std::vector<Room>& rooms = {}, 
		const std::vector<Employee>& employees = {});

	std::string GetName() const;

	void AddRoom(const Room& room);
	void AddEmployee(const Employee& employee);

	void DeleteEmployee(const int& ID);
	void DeleteRoom(const int& roomNumber);

	void MakeRoomDirty(const int& roomNumber);

	void DisplayRoomInfo() const;
	void DisplayEmployeeInfo() const;

	
	
	void AddRoom();
};

