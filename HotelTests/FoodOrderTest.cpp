#include "gtest/gtest.h"
#include "C:\Education\University\POIS\Hotel_OOP\Hotel_OOP\FoodOrder.h"
#include "C:\Education\University\POIS\Hotel_OOP\Hotel_OOP\MenuItem.h"
#include <sstream>


TEST(FoodOrderTest, ConstructorInitializesCorrectly) {
    MenuItem pizza("Pizza", 12.99f);
    FoodOrder foodOrder(pizza);

    EXPECT_EQ(foodOrder.GetMenuItem().GetName(), "Pizza");
    EXPECT_EQ(foodOrder.GetMenuItem().GetPrice(), 12.99f);
}

TEST(FoodOrderTest, ExecuteServiceDisplaysCorrectMessage) {
    MenuItem pizza("Pizza", 12.99f);
    FoodOrder foodOrder(pizza);

    testing::internal::CaptureStdout();

    foodOrder.ExecuteService();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Food Order: Pizza is being prepared and delivered.\n");
}

TEST(FoodOrderTest, PriceIsCorrect) {
    MenuItem pasta("Pasta", 8.50f);
    FoodOrder foodOrder(pasta);

    EXPECT_EQ(foodOrder.GetPrice(), 8.50f);
}
