#include "MenuItem.h"

MenuItem::MenuItem(const std::string& name, float price) : m_name(name), m_price(price) {}

std::string MenuItem::GetName() const {
    return m_name;
}

float MenuItem::GetPrice() const {
    return m_price;
}