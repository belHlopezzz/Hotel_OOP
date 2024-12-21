#include "C:\Education\University\POIS\Hotel_OOP\Hotel_OOP\Human.h"
#include "C:\Education\University\POIS\Hotel_OOP\Hotel_OOP\Employee.h"
#include "gtest/gtest.h"

TEST(EmployeeTest, ConstructorInitializesFields) {
    Employee employee("John", "Doe", 5000.0f, "Manager");

    EXPECT_EQ(employee.GetFirstName(), "John");
    EXPECT_EQ(employee.GetSecondName(), "Doe");
    EXPECT_EQ(employee.GetSalary(), 5000.0f);
    EXPECT_EQ(employee.GetPosition(), "Manager");
    EXPECT_GT(employee.GetID(), 0);  
}


TEST(EmployeeTest, SetAndGetID) {
    Employee employee("Alice", "Smith", 4500.0f, "Clerk");

    int newID = 10;
    employee.SetID(newID);

    EXPECT_EQ(employee.GetID(), newID);
}


TEST(EmployeeTest, DestructorDecrementsBufferID) {
    {
        Employee employee1("Bob", "Brown", 5500.0f, "Developer");
        Employee employee2("Eve", "White", 6500.0f, "Designer");

        EXPECT_EQ(employee1.GetID(), 1);
        EXPECT_EQ(employee2.GetID(), 2);
    }

    Employee employee3("Charlie", "Green", 7000.0f, "Tester");
    EXPECT_EQ(employee3.GetID(), 1);  
}


TEST(EmployeeTest, GetPosition) {
    Employee employee("Grace", "Lee", 6000.0f, "Manager");

    EXPECT_EQ(employee.GetPosition(), "Manager");
}

TEST(EmployeeTest, GetSalary) {
    Employee employee("Tom", "Jones", 8000.0f, "CEO");

    EXPECT_EQ(employee.GetSalary(), 8000.0f);
}

