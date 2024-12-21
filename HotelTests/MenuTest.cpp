#include "C:\Education\University\POIS\Hotel_OOP\Hotel_OOP\Menu.h"
#include "C:\Education\University\POIS\Hotel_OOP\Hotel_OOP\MenuItem.h"
#include <gtest/gtest.h>
#include <sstream>


TEST(MenuTest, ConstructorInitializesMenuName) {
    Menu menu("Breakfast Menu");
    std::ostringstream output;
    testing::internal::CaptureStdout();
    menu.DisplayMenu();
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "Menu: Breakfast Menu\n");
}

TEST(MenuTest, AddMenuItem) {
    Menu menu("Lunch Menu");
    MenuItem item1("Burger", 10.0f);
    MenuItem item2("Salad", 15.0f);
    menu.AddMenuItem(item1);
    menu.AddMenuItem(item2);

    std::ostringstream output;
    output << "Menu: Lunch Menu\n";
    output << "Burger - $10\n";
    output << "Salad - $15\n";

    testing::internal::CaptureStdout();
    menu.DisplayMenu();
    EXPECT_EQ(testing::internal::GetCapturedStdout(), output.str());
}

TEST(MenuTest, DisplayEmptyMenu) {
    Menu menu("Dinner Menu");
    testing::internal::CaptureStdout();
    menu.DisplayMenu();
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "Menu: Dinner Menu\n");
}
