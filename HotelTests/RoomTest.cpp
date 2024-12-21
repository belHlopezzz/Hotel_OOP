#include "gtest/gtest.h"
#include "C:\Education\University\POIS\Hotel_OOP\Hotel_OOP\Room.h"


TEST(RoomTest, ConstructorInitializesStandardRoom) {
    Room room(2, false);
    EXPECT_EQ(room.GetNumberOfBeds(), 2);
    EXPECT_FALSE(room.GetIsVIP());
    EXPECT_TRUE(room.GetIsClean());
    EXPECT_TRUE(room.GetIsAvailable());
    EXPECT_FLOAT_EQ(room.GetPricePerNight(), 20 * 2 + 30); 
}


TEST(RoomTest, ConstructorInitializesVIPRoom) {
    Room room(3, true);
    EXPECT_EQ(room.GetNumberOfBeds(), 3);
    EXPECT_TRUE(room.GetIsVIP());
    EXPECT_TRUE(room.GetIsClean());
    EXPECT_TRUE(room.GetIsAvailable());
    EXPECT_FLOAT_EQ(room.GetPricePerNight(), 15 * 3 * 3 - 25 * 3 + 90);
}


TEST(RoomTest, ConstructorThrowsExceptionForNegativeBeds) {
    EXPECT_THROW(Room(-1, false), std::invalid_argument);
}


TEST(RoomTest, SetIsCleanWorksCorrectly) {
    Room room(1, false);
    room.SetIsClean(false);
    EXPECT_FALSE(room.GetIsClean());
}


TEST(RoomTest, SetIsAvailableWorksCorrectly) {
    Room room(2, true);
    room.SetIsAvailble(false);
    EXPECT_FALSE(room.GetIsAvailable());
}


TEST(RoomTest, RoomNumbersAreUnique) {
    Room room1(2, false);
    Room room2(3, true);
    EXPECT_NE(room1.GetRoomNumber(), room2.GetRoomNumber());
}


TEST(RoomTest, SetRoomNumberWorksCorrectly) {
    Room room(2, false);
    room.SetRoomNumber(101);
    EXPECT_EQ(room.GetRoomNumber(), 101);
}


TEST(RoomTest, DestructorDecrementsRoomNumberBuffer) {
    int initialRoomNumber;
    {
        Room room(2, false);
        initialRoomNumber = room.GetRoomNumber();
    }
    Room newRoom(3, true);
    EXPECT_EQ(newRoom.GetRoomNumber(), initialRoomNumber);
}
