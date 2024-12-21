#include "C:\Education\University\POIS\Hotel_OOP\Hotel_OOP\Human.h"
#include "gtest/gtest.h"

TEST(HumanTest, ConstructorInitializesFirstName) {
    Human person("John", "Doe");
    EXPECT_EQ(person.GetFirstName(), "John");
}

TEST(HumanTest, ConstructorInitializesSecondName) {
    Human person("Jane", "Smith");
    EXPECT_EQ(person.GetSecondName(), "Smith");
}

TEST(HumanTest, FullNameInitialization) {
    Human person("Alice", "Johnson");
    EXPECT_EQ(person.GetFirstName(), "Alice");
    EXPECT_EQ(person.GetSecondName(), "Johnson");
}