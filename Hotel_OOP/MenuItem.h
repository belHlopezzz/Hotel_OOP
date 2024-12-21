#pragma once
#include <string>

class MenuItem {
private:
    std::string m_name;
    float m_price;

public:
    MenuItem(const std::string& name, float price);

    std::string GetName() const;
    float GetPrice() const;
};