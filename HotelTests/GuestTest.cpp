#include "C:\Education\University\POIS\Hotel_OOP\Hotel_OOP\Guest.h"
#include "C:\Education\University\POIS\Hotel_OOP\Hotel_OOP\Hotel.h"
#include "C:\Education\University\POIS\Hotel_OOP\Hotel_OOP\Administrator.h"
#include "C:\Education\University\POIS\Hotel_OOP\Hotel_OOP\Review.h"
#include "C:\Education\University\POIS\Hotel_OOP\Hotel_OOP\FoodOrder.h"
#include "gtest/gtest.h"

TEST(GuestTest, ConstructorInitialization) {
    Guest guest("John", "Doe", 100.0f);

    EXPECT_EQ(guest.GetFirstName(), "John");
    EXPECT_EQ(guest.GetSecondName(), "Doe");
    EXPECT_FLOAT_EQ(guest.GetBalance(), 100.0f);
    EXPECT_EQ(guest.GetKeyFromRoom(), 0);
    EXPECT_EQ(guest.GetID(), 1);
}


TEST(GuestTest, SetKeyFromRoom) {
    Guest guest("Jane", "Smith", 150.0f);
    guest.SetKeyFromRoom(123);

    EXPECT_EQ(guest.GetKeyFromRoom(), 123);
}

TEST(GuestTest, SetBalance) {
    Guest guest("John", "Doe", 100.0f);
    guest.SetBalance(200.0f);

    EXPECT_FLOAT_EQ(guest.GetBalance(), 200.0f);
}


TEST(GuestTest, OrderFoodWithSufficientBalance) {
    Guest guest("Alice", "Brown", 50.0f);
    MenuItem burger("Burger", 15.0f);
    Service* foodOrder = new FoodOrder(burger);

    testing::internal::CaptureStdout();
    guest.OrderService(foodOrder);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_FLOAT_EQ(guest.GetBalance(), 35.0f); 
    EXPECT_NE(output.find("Service ordered: Food Order"), std::string::npos);
    EXPECT_NE(output.find("Food Order: Burger is being prepared and delivered."), std::string::npos);

    delete foodOrder;
}

TEST(GuestTest, OrderFoodWithInsufficientBalance) {
    Guest guest("Bob", "White", 10.0f);
    MenuItem steak("Steak", 25.0f);
    Service* foodOrder = new FoodOrder(steak);

    testing::internal::CaptureStdout();
    guest.OrderService(foodOrder);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_FLOAT_EQ(guest.GetBalance(), 10.0f); 
    EXPECT_NE(output.find("Insufficient balance to order: Food Order"), std::string::npos);

    delete foodOrder;
}

TEST(GuestTest, LeaveReview) {
    Guest guest("Eve", "Green", 80.0f);
    Review review = guest.LeaveReview(5, "Great stay!", "2024-05-01");

    testing::internal::CaptureStdout();
    review.DisplayReview();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Review Date: 2024-05-01"), std::string::npos);
    EXPECT_NE(output.find("Rating: 5/5"), std::string::npos);
    EXPECT_NE(output.find("Comment: Great stay!"), std::string::npos);
    EXPECT_NE(output.find("Guest: Eve Green"), std::string::npos);
}
