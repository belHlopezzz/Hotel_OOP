#include "C:\Education\University\POIS\Hotel_OOP\Hotel_OOP\Administrator.h"
#include "C:\Education\University\POIS\Hotel_OOP\Hotel_OOP\Room.h"
#include "C:\Education\University\POIS\Hotel_OOP\Hotel_OOP\Human.h"
#include "C:\Education\University\POIS\Hotel_OOP\Hotel_OOP\Employee.h"
#include "C:\Education\University\POIS\Hotel_OOP\Hotel_OOP\Hotel.h"
#include "C:\Education\University\POIS\Hotel_OOP\Hotel_OOP\Guest.h"
#include "gtest/gtest.h"

TEST(AdministratorTest, BedGuest_SuccessfulBooking) {
    Hotel hotel(5, "Luxury Stay", { Room(2, false) }, {});
    Administrator admin("John", "Doe");
    Guest guest("Alice", "Smith", 300.0f);

    EXPECT_NO_THROW(admin.BedGuest(guest, 2, 2, false, hotel));
    EXPECT_EQ(guest.GetBalance(), 300.0f - hotel.GetRooms()[0].GetPricePerNight() * 2);
    EXPECT_FALSE(hotel.GetRooms()[0].GetIsAvailable());
}

TEST(AdministratorTest, BedGuest_InsufficientFunds) {
    Hotel hotel(5, "Budget Stay", { Room(1, false) }, {});
    Administrator admin("John", "Doe");
    Guest guest("Bob", "Brown", 20.0f);

    EXPECT_THROW(admin.BedGuest(guest, 1, 1, false, hotel), std::runtime_error);
    EXPECT_TRUE(hotel.GetRooms()[0].GetIsAvailable());
}

TEST(AdministratorTest, BedGuest_NoAvailableRooms) {
    Hotel hotel(5, "No Vacancy", {}, {});
    Administrator admin("Jane", "Smith");
    Guest guest("Eve", "Johnson", 500.0f);

    EXPECT_THROW(admin.BedGuest(guest, 2, 1, false, hotel), std::runtime_error);
}

TEST(AdministratorTest, BedGuest_GuestAlreadyHasRoomKey) {
    Hotel hotel(4, "Holiday Inn", { Room(1, false) }, {});
    Administrator admin("Alex", "Morgan");
    Guest guest("Dana", "Hill", 200.0f);
    admin.BedGuest(guest, 1, 1, false, hotel);
    EXPECT_EQ(guest.GetKeyFromRoom(), hotel.GetRooms()[0].GetRoomNumber());

    EXPECT_THROW(admin.BedGuest(guest, 1, 1, false, hotel), std::runtime_error);
}
