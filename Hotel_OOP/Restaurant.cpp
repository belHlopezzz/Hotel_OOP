#include "Restaurant.h"

Restaurant::Restaurant(const std::string& name)
	: m_name(name) 
{
	m_menus.reserve(3);
}

std::vector<Menu> Restaurant::GetMenus() const
{
	return m_menus;
}

void Restaurant::AddMenu(Menu& menu)
{
	m_menus.emplace_back(menu);
}

void Restaurant::DisplayRestaurantInfo() const
{
	std::cout << "Restaurant: " << m_name << std::endl;
	std::cout << "Menus available:" << std::endl;
	for (const auto& menu : m_menus) {
		menu.DisplayMenu();
	}
}









