#pragma once
#include <iostream>
#include <string>
#include "Guest.h"

class Review {
private:
    std::string m_date;     
    int m_rating;
    std::string m_comment;
    Guest* m_guest;

public:
    Review(const std::string& date, int rating, const std::string& comment, Guest* guest);

    void SetRating(int newRating);
    int GetRating() const;

    void SetComment(const std::string& newComment);
    std::string GetComment() const;

    void DisplayReview() const;
};
