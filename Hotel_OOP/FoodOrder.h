#pragma once
#include "Service.h"
#include "MenuItem.h"
#include <iostream>

class FoodOrder : public Service
{
private:
	MenuItem m_menuItem;

public:
	FoodOrder(const MenuItem& menuItem);

	MenuItem GetMenuItem() const;

	void ExecuteService() override;
};

