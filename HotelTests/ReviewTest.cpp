#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include "C:\Education\University\POIS\Hotel_OOP\Hotel_OOP\Review.h"
#include "C:\Education\University\POIS\Hotel_OOP\Hotel_OOP\Guest.h"

TEST(ReviewTest, SetRating) {
    Guest guest("John", "Doe", 10.0f);
    Review review("2024-12-21", 4, "Great stay!", &guest);

    review.SetRating(5);

    EXPECT_EQ(review.GetRating(), 5);
}

TEST(ReviewTest, SetComment) {
    Guest guest("John", "Doe", 10.0f);
    Review review("2024-12-21", 4, "Great stay!", &guest);

    review.SetComment("Amazing experience!");

    EXPECT_EQ(review.GetComment(), "Amazing experience!");
}

TEST(ReviewTest, DisplayReview_WithGuest) {
    Guest guest("John", "Doe", 10.0f);
    Review review("2024-12-21", 4, "Great stay!", &guest);

    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    review.DisplayReview();

    std::cout.rdbuf(old);

    EXPECT_NE(buffer.str().find("Review Date: 2024-12-21"), std::string::npos);
    EXPECT_NE(buffer.str().find("Rating: 4/5"), std::string::npos);
    EXPECT_NE(buffer.str().find("Comment: Great stay!"), std::string::npos);
    EXPECT_NE(buffer.str().find("Guest: John Doe"), std::string::npos);
}

TEST(ReviewTest, DisplayReview_WithoutGuest) {
    Review review("2024-12-21", 4, "Great stay!", nullptr);

    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    review.DisplayReview();

    std::cout.rdbuf(old);

    EXPECT_NE(buffer.str().find("Review Date: 2024-12-21"), std::string::npos);
    EXPECT_NE(buffer.str().find("Rating: 4/5"), std::string::npos);
    EXPECT_NE(buffer.str().find("Comment: Great stay!"), std::string::npos);
    EXPECT_NE(buffer.str().find("Guest: Unknown"), std::string::npos);
}
