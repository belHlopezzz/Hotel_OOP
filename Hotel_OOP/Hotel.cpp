#include "Hotel.h"

Hotel::Hotel(const int& numberOfStars, const std::string& name, const std::vector<Room>& rooms,
    const std::vector<Employee>& employees)
	:m_name(name), m_numberOfStars(numberOfStars)
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


void Hotel::AddRoom(const Room& room)
{
    m_rooms.emplace_back(room);
}

void Hotel::AddRoom()
{
    std::vector<Room>& rooms = RoomRepository::GetRooms();
    rooms.emplace_back(3, false);
    if (rooms.empty())
    {
        std::cout << "No rooms available.\n\n";
    }
    else
    {
        for (const auto& room : rooms)
        {
            std::cout << "Room Number:     #" << room.GetRoomNumber() << "\n"
                << "VIP Status:      " << (room.GetIsVIP() ? "VIP" : "NOT VIP") << "\n"
                << "Clean Status:    " << (room.GetIsClean() ? "Clean" : "Needs Cleaning") << "\n"
                << "Number of Beds:  " << room.GetNumberOfBeds() << "\n"
                << "Price per Night: $" << room.GetPricePerNight() << "\n"
                << "Available:       " << (room.GetIsAvailable() ? "Available" : "NOT Available") << "\n"
                << "-----------------------------------------------\n\n";
        }
    }
}

void Hotel::AddEmployee(const Employee& employee)
{
    m_employees.emplace_back(employee);
}

void Hotel::DeleteEmployee(const int& ID)
{
    if (m_employees.empty())
        throw std::runtime_error("Warning: There are no employees yet\n\n");

    std::vector<Employee>::iterator it = m_employees.begin();
    bool employeeFound = false;
    while (it != m_employees.end())
    {
        if (it->GetID() == ID)
        {
            it = m_employees.erase(it);
            employeeFound = true;
            break;
        }
        it++;
    }
    if (!employeeFound)
        throw std::runtime_error("Warning: Employee with ID " + std::to_string(ID) + " was not found\n\n");

    while (it != m_employees.end())
    {
        it->SetID(it->GetID() - 1);
        it++;
    }
}

void Hotel::DeleteRoom(const int& roomNumber)
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

void Hotel::MakeRoomDirty(const int& roomNumber)
{
    for (auto& room : m_rooms)
    {
        if (room.GetRoomNumber() == roomNumber)
        {
            room.SetIsClean(false);
            return;
        }
    }
    throw std::runtime_error("Warning: Room " + std::to_string(roomNumber) + " doesn't exist.\n\n");
}

void Hotel::DisplayRoomInfo() const
{
    std::cout << "\n";
    std::cout << "=============================================\n";
    std::cout << "               HOTEL OVERVIEW                \n";
    std::cout << "=============================================\n\n";

    std::cout << "------------- [ ROOM INFORMATION ] ------------\n\n";

    if (m_rooms.empty())
    {
        std::cout << "No rooms available.\n\n";
    }
    else
    {
        for (const auto& room : m_rooms)
        {
            std::cout << "Room Number:     #" << room.GetRoomNumber() << "\n"
                << "VIP Status:      " << (room.GetIsVIP() ? "VIP" : "NOT VIP") << "\n"
                << "Clean Status:    " << (room.GetIsClean() ? "Clean" : "Needs Cleaning") << "\n"
                << "Number of Beds:  " << room.GetNumberOfBeds() << "\n"
                << "Price per Night: $" << room.GetPricePerNight() << "\n"
                << "Available:       " << (room.GetIsAvailable() ? "Available" : "NOT Available") << "\n"
                << "-----------------------------------------------\n\n";
        }
    }

    std::cout << "=============================================\n";
    std::cout << "            END OF HOTEL OVERVIEW             \n";
    std::cout << "=============================================\n\n";
}

void Hotel::DisplayEmployeeInfo() const
{
    std::cout << "=============================================\n\n";
    std::cout << "----------- [ EMPLOYEE INFORMATION ] -----------\n\n";

    if (m_employees.empty())
    {
        std::cout << "No employees registered.\n\n";
    }
    else
    {
        for (const auto& employee : m_employees)
        {
            std::cout << "Employee ID:     #" << employee.GetID() << "\n"
                << "Name:            " << employee.GetFirstName() << " " << employee.GetSecondName() << "\n"
                << "Salary:          $" << employee.GetSalary() << "\n"
                << "Position:        " << employee.GetPosition() << "\n"
                << "-----------------------------------------------\n\n";
        }
    }

    std::cout << "=============================================\n";
    std::cout << "            END OF HOTEL OVERVIEW             \n";
    std::cout << "=============================================\n\n";
}



