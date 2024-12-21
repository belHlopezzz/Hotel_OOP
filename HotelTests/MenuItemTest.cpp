#include "C:\Education\University\POIS\Hotel_OOP\Hotel_OOP\MenuItem.h"
#include <gtest/gtest.h>


TEST(MenuItemTest, ConstructorInitializesName) {
    MenuItem item("Pizza", 12.5f);
    EXPECT_EQ(item.GetName(), "Pizza");
}


TEST(MenuItemTest, ConstructorInitializesPrice) {
    MenuItem item("Burger", 8.75f);
    EXPECT_FLOAT_EQ(item.GetPrice(), 8.75f);
}


TEST(MenuItemTest, ConstructorInitializesNameAndPrice) {
    MenuItem item("Pasta", 15.0f);
    EXPECT_EQ(item.GetName(), "Pasta");
    EXPECT_FLOAT_EQ(item.GetPrice(), 15.0f);
}


TEST(MenuItemTest, ConstructorAcceptsNegativePrice) {
    MenuItem item("Discounted Item", -5.0f);
    EXPECT_FLOAT_EQ(item.GetPrice(), -5.0f);
    EXPECT_EQ(item.GetName(), "Discounted Item");
}
