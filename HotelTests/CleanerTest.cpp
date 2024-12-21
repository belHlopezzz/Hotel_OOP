#include "C:\Education\University\POIS\Hotel_OOP\Hotel_OOP\Human.h"
#include "C:\Education\University\POIS\Hotel_OOP\Hotel_OOP\Employee.h"
#include "C:\Education\University\POIS\Hotel_OOP\Hotel_OOP\Cleaner.h"
#include "C:\Education\University\POIS\Hotel_OOP\Hotel_OOP\Room.h"
#include "gtest/gtest.h"


TEST(CleanerTest, ConstructorInitializesFields) {
    Cleaner cleaner("Alice", "Smith");

    EXPECT_EQ(cleaner.GetFirstName(), "Alice");
    EXPECT_EQ(cleaner.GetSecondName(), "Smith");
    EXPECT_EQ(cleaner.GetSalary(), 800.0f);
    EXPECT_EQ(cleaner.GetPosition(), "Cleaner");
    EXPECT_EQ(cleaner.GetNumberOfCleanedRooms(), 0);
}

TEST(CleanerTest, CleanRoomIncreasesCleanedRoomsCount) {
    Room room(2, false);  
    Cleaner cleaner("John", "Doe");

    EXPECT_EQ(cleaner.GetNumberOfCleanedRooms(), 0);  
    cleaner.CleanRoom(room);
    EXPECT_EQ(room.GetIsClean(), true);
    EXPECT_EQ(cleaner.GetNumberOfCleanedRooms(), 1);
}

TEST(CleanerTest, CleanMultipleRooms) {
    Room room1(1, false);  
    Room room2(2, true);   
    Room room3(3, false);  
    Cleaner cleaner("Grace", "Lee");

    
    EXPECT_EQ(cleaner.GetNumberOfCleanedRooms(), 0);
    cleaner.CleanRoom(room1);
    cleaner.CleanRoom(room2);
    cleaner.CleanRoom(room3);

    EXPECT_EQ(room1.GetIsClean(), true);
    EXPECT_EQ(room2.GetIsClean(), true);
    EXPECT_EQ(room3.GetIsClean(), true);
    EXPECT_EQ(cleaner.GetNumberOfCleanedRooms(), 3);
}