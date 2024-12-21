#include "C:\Education\University\POIS\Hotel_OOP\Hotel_OOP\Hotel.h"
#include "C:\Education\University\POIS\Hotel_OOP\Hotel_OOP\Employee.h"
#include "C:\Education\University\POIS\Hotel_OOP\Hotel_OOP\Room.h"
#include "C:\Education\University\POIS\Hotel_OOP\Hotel_OOP\Restaurant.h"
#include "gtest/gtest.h"

TEST(HotelTest, CreateHotelAndCheckName) {
    Hotel hotel(5, "Luxury Inn");
    EXPECT_EQ(hotel.GetName(), "Luxury Inn");
}

TEST(HotelTest, AddRoom) {
    Hotel hotel(4, "Cozy Stay");
    hotel.AddRoom(2, false);

    auto rooms = hotel.GetRooms();
    ASSERT_EQ(rooms.size(), 1);
    EXPECT_EQ(rooms[0].GetNumberOfBeds(), 2);
    EXPECT_FALSE(rooms[0].GetIsVIP());
}

TEST(HotelTest, DeleteRoom) {
    Room::ResetRoomNumberBuffer();
    Hotel hotel(4, "Holiday Spot");
    hotel.AddRoom(2, false);
    hotel.AddRoom(3, true);

    hotel.DeleteRoom(1);

    auto rooms = hotel.GetRooms();
    ASSERT_EQ(rooms.size(), 1);
    EXPECT_EQ(rooms[0].GetNumberOfBeds(), 3);
    EXPECT_TRUE(rooms[0].GetIsVIP());
}

TEST(HotelTest, AddEmployee) {
    Hotel hotel(5, "Elite Hotel");
    Employee employee("John", "Doe", 1, "Receptionist");

    hotel.AddEmployee(employee);

    EXPECT_NO_THROW(hotel.DeleteEmployee(1));
}

TEST(HotelTest, DeleteEmployee) {
    Hotel hotel(3, "Budget Inn");
    Employee employee1("Alice", "Brown", 1.0f, "Cleaner");
    Employee employee2("Bob", "Smith", 2.0f, "Manager");

    hotel.AddEmployee(employee1);
    hotel.AddEmployee(employee2);
    hotel.DeleteEmployee(1);
    std::vector<Employee> employes = hotel.GetEmployees();
    ASSERT_EQ(employes.size(), 1);
    EXPECT_EQ(employes[0].GetFirstName(), "Alice");
}

TEST(HotelTest, SetAndDisplayRestaurantInfo) {
    Hotel hotel(4, "Foodie Haven");
    Restaurant restaurant("Gourmet Paradise");

    hotel.SetRestaurant(&restaurant);

    testing::internal::CaptureStdout();
    hotel.DisplayRestaurantInfo();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Gourmet Paradise"), std::string::npos);
}


TEST(HotelTest, MakeRoomDirty) {
    Hotel hotel(4, "Comfort Stay");
    Room::ResetRoomNumberBuffer();
    hotel.AddRoom(2, false);

    hotel.MakeRoomDirty(1);

    auto rooms = hotel.GetRooms();
    ASSERT_EQ(rooms.size(), 1);
    EXPECT_FALSE(rooms[0].GetIsClean());
}

TEST(HotelTest, UpdateRoomAvailability) {
    Hotel hotel(3, "Comfort Inn");
    Room::ResetRoomNumberBuffer();
    hotel.AddRoom(2, false);

    hotel.UpdateRoomAvailability(1, false);

    auto rooms = hotel.GetRooms();
    ASSERT_EQ(rooms.size(), 1);
    EXPECT_FALSE(rooms[0].GetIsAvailable());
}