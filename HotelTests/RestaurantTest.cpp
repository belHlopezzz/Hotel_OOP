#include "C:\Education\University\POIS\Hotel_OOP\Hotel_OOP\Menu.h"
#include "C:\Education\University\POIS\Hotel_OOP\Hotel_OOP\MenuItem.h"
#include "C:\Education\University\POIS\Hotel_OOP\Hotel_OOP\Restaurant.h"
#include "gtest/gtest.h"
#include <sstream>

TEST(RestaurantTest, ConstructorInitializesName) {
    Restaurant restaurant("Gourmet Place");
    std::ostringstream output;
    testing::internal::CaptureStdout();
    restaurant.DisplayRestaurantInfo();
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "Restaurant: Gourmet Place\nMenus available:\n");
}


TEST(RestaurantTest, DisplayRestaurantInfoShowsMenus) {
    Restaurant restaurant("Bistro Delight");

    Menu breakfastMenu("Breakfast");
    Menu lunchMenu("Lunch");
    MenuItem item1("Pancakes", 8.5f);
    MenuItem item2("Burger", 12.0f);
    breakfastMenu.AddMenuItem(item1);
    lunchMenu.AddMenuItem(item2);

    restaurant.AddMenu(breakfastMenu);
    restaurant.AddMenu(lunchMenu);

    std::ostringstream expectedOutput;
    expectedOutput << "Restaurant: Bistro Delight\n";
    expectedOutput << "Menus available:\n";
    expectedOutput << "Menu: Breakfast\n";
    expectedOutput << "Pancakes - $8.5\n";
    expectedOutput << "Menu: Lunch\n";
    expectedOutput << "Burger - $12\n";

    testing::internal::CaptureStdout();
    restaurant.DisplayRestaurantInfo();
    EXPECT_EQ(testing::internal::GetCapturedStdout(), expectedOutput.str());
}
