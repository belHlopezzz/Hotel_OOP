#include "C:\Education\University\POIS\Hotel_OOP\Hotel_OOP\RoomCleaning.h"
#include "C:\Education\University\POIS\Hotel_OOP\Hotel_OOP\Room.h"
#include "gtest/gtest.h"


TEST(RoomCleaningTest, ConstructorInitializesFields) {
    Room room(2, false);  
    RoomCleaning roomCleaning(&room);

    EXPECT_EQ(roomCleaning.GetServiceName(), "Room Cleaning");
    EXPECT_EQ(roomCleaning.GetPrice(), 20.0f);
    EXPECT_EQ(roomCleaning.GetRoom(), &room);  
}


TEST(RoomCleaningTest, ExecuteServiceCleansRoom) {
    Room room(1, true);  
    RoomCleaning roomCleaning(&room);

    EXPECT_EQ(room.GetIsClean(), true);  

    roomCleaning.ExecuteService();

    EXPECT_EQ(room.GetIsClean(), true);  
    EXPECT_EQ(roomCleaning.GetRoom(), &room);  
}


TEST(RoomCleaningTest, VIPRoomPrice) {
    Room vipRoom(3, true);  
    RoomCleaning vipRoomCleaning(&vipRoom);

    EXPECT_EQ(vipRoomCleaning.GetPrice(), 30.0f); 
}

TEST(RoomCleaningTest, RegularRoomPrice) {
    Room regularRoom(2, false);  
    RoomCleaning regularRoomCleaning(&regularRoom);

    EXPECT_EQ(regularRoomCleaning.GetPrice(), 20.0f); 
}
