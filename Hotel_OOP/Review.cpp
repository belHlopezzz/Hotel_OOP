#include "Review.h"

Review::Review(const std::string& date, int rating, const std::string& comment, Guest* guest)
    : m_date(date), m_rating(rating), m_comment(comment), m_guest(guest) {
}

void Review::SetRating(int newRating) {
    if (newRating >= 1 && newRating <= 5) {
        m_rating = newRating;
    }
    else {
        std::cout << "Rating must be between 1 and 5." << std::endl;
    }
}

int Review::GetRating() const
{
    return m_rating;
}

void Review::SetComment(const std::string& newComment) {
    m_comment = newComment;
}

std::string Review::GetComment() const
{
    return m_comment;
}

void Review::DisplayReview() const {
    std::cout << "Review Date: " << m_date << std::endl;
    std::cout << "Rating: " << m_rating << "/5" << std::endl;
    std::cout << "Comment: " << m_comment << std::endl;
    if (m_guest) {
        std::cout << "Guest: " << m_guest->GetFirstName() << " " << m_guest->GetSecondName() << std::endl;
    }
    else {
        std::cout << "Guest: Unknown" << std::endl;
    }
}
