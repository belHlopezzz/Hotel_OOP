#pragma once

#include "Room.h"
#include <vector>
#include "Employee.h"
#include <string>
#include <stdexcept>
#include "Restaurant.h"

class Hotel
{
private:
	std::vector<Room> m_rooms;
	std::vector<Employee> m_employees;
	std::string m_name;
	int m_numberOfStars;
	Restaurant* m_restaurant;


public:
	Hotel(int numberOfStars, const std::string& name, const std::vector<Room>& rooms = {}, 
		const std::vector<Employee>& employees = {});

	std::string GetName() const;
	std::vector<Room> GetRooms() const;
	std::vector<Employee> GetEmployees() const;

	void SetRestaurant(Restaurant* restaurant);

	void AddRoom(int bedNumber, bool isVIP);
	void AddEmployee(Employee& employee);

	void DeleteEmployee(int ID);
	void DeleteRoom(int roomNumber);

	void MakeRoomDirty(int roomNumber);

	void UpdateRoomAvailability(int roomNumber, bool isAvailable);

	void DisplayRestaurantInfo() const;
};

