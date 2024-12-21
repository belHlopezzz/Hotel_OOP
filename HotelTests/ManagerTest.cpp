#include <gtest/gtest.h>
#include <sstream>
#include "C:\Education\University\POIS\Hotel_OOP\Hotel_OOP\Manager.h"
#include "C:\Education\University\POIS\Hotel_OOP\Hotel_OOP\Employee.h"
#include "C:\Education\University\POIS\Hotel_OOP\Hotel_OOP\Hotel.h"

TEST(ManagerTest, HireEmployee) {
    Hotel hotel(5, "Luxury Hotel");
    Employee employee("John", "Doe", 1200.0f, "Receptionist");
    Manager manager("Alice", "Smith");

    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    manager.HireEmployee(hotel, employee);

    std::cout.rdbuf(old);

    EXPECT_NE(buffer.str().find("Employee John Doe has been hired."), std::string::npos);
    EXPECT_EQ(hotel.GetRooms().size(), 0);
    EXPECT_EQ(hotel.GetEmployees().size(), 1);
}

TEST(ManagerTest, FireEmployee) {
    Hotel hotel(5, "Luxury Hotel");
    Employee employee("John", "Doe", 1200.0f, "Receptionist");
    hotel.AddEmployee(employee);
    Manager manager("Alice", "Smith");

    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    manager.FireEmployee(hotel, employee.GetID());

    std::cout.rdbuf(old);

    EXPECT_NE(buffer.str().find("Employee with ID " + std::to_string(employee.GetID()) + " has been fired."), std::string::npos);
    EXPECT_EQ(hotel.GetEmployees().size(), 0);
}
