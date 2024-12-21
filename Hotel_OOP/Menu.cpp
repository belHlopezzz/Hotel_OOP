#include "Menu.h"

Menu::Menu(const std::string& menuName) : m_menuName(menuName) 
{
    m_items.reserve(5);
}

void Menu::AddMenuItem(const MenuItem& item) {
    m_items.emplace_back(item);
}

void Menu::DisplayMenu() const {
    std::cout << "Menu: " << m_menuName << std::endl;
    for (const auto& item : m_items) {
        std::cout << item.GetName() << " - $" << item.GetPrice() << std::endl;
    }
}
