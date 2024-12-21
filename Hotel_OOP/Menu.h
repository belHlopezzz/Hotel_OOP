#pragma once
#include "MenuItem.h"
#include <string>
#include <vector>
#include <iostream>

class Menu {
private:
    std::string m_menuName;
    std::vector<MenuItem> m_items;

public:
    Menu(const std::string& menuName);

    void AddMenuItem(const MenuItem& item);
    void DisplayMenu() const;
};

