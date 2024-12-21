#include "Hotel.h"

Hotel::Hotel(int numberOfStars, const std::string& name, const std::vector<Room>& rooms,
    const std::vector<Employee>& employees)
	:m_name(name), m_numberOfStars(numberOfStars), m_restaurant(nullptr)
{
    m_rooms.reserve(40);
    m_employees.reserve(10);

	m_rooms = rooms;
    m_employees = employees;
}

std::string Hotel::GetName() const
{
    return m_name;
}

std::vector<Room> Hotel::GetRooms() const
{
    return m_rooms;
}

std::vector<Employee> Hotel::GetEmployees() const
{
    return m_employees;
}

void Hotel::SetRestaurant(Restaurant* restaurant)
{
    m_restaurant = restaurant;
}


void Hotel::AddRoom(int bedNumber, bool isVIP)
{
    m_rooms.emplace_back(bedNumber, isVIP);
}

void Hotel::AddEmployee(Employee& employee)
{
    m_employees.emplace_back(employee);
}

void Hotel::DeleteEmployee(int ID)
{
    if (m_employees.empty()){
        std::cout << "Warning: There are no employees yet\n\n";
        return;
    }
    auto it = m_employees.begin();
    bool employeeFound = false;
    while (it != m_employees.end()) {
        if (it->GetID() == ID) {
            it = m_employees.erase(it);
            employeeFound = true;
            break;
        }
        else  {
            ++it;
        }
    }
    if (!employeeFound)  {
        std::cout << "Warning: Employee with ID " << ID << " was not found\n\n";
        return;
    }
    for (; it != m_employees.end(); ++it)  {
        it->SetID(it->GetID() - 1);
    }
}


void Hotel::DeleteRoom(int roomNumber)
{
    if (m_rooms.empty())
        throw std::runtime_error("Hotel" + m_name + "doesn't have rooms yet.\n");

    std::vector<Room>::iterator it = m_rooms.begin();
    bool roomFound = false;
    while (it != m_rooms.end())
    {
        if (it->GetRoomNumber() == roomNumber)
        {
            it = m_rooms.erase(it);
            roomFound = true;
            break; 
        }
        it++;
    }  
    if (!roomFound)
        throw std::runtime_error("Room number " + std::to_string(roomNumber) + " not found.\n");
    while (it != m_rooms.end())
    {
        it->SetRoomNumber(it->GetRoomNumber() - 1);
        it++;
    }
}

void Hotel::MakeRoomDirty(int roomNumber)
{
    for (auto& room : m_rooms)
    {
        if (room.GetRoomNumber() == roomNumber)
        {
            room.SetIsClean(false);
            return;
        }
    }
    std::cout << "This room doesn't exist\n";
}

void Hotel::UpdateRoomAvailability(int roomNumber, bool isAvailable)
{
    for (auto& room : m_rooms)
    {
        if (room.GetRoomNumber() == roomNumber)
        {
            room.SetIsAvailble(isAvailable);
            return;
        }
    }
}

void Hotel::DisplayRestaurantInfo() const
{
    m_restaurant->DisplayRestaurantInfo();
}



