#pragma once
#include <string>
#include <vector>
#include "Menu.h"

class Restaurant
{
private:
	std::string m_name;
	std::vector<Menu> m_menus;
	int m_michelinStar;

public:
	Restaurant(const std::string& name);
	
	std::vector<Menu> GetMenus() const;

	void AddMenu(Menu& menu);
	void DisplayRestaurantInfo() const;

};

