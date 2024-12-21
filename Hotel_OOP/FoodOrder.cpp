#include "FoodOrder.h"

FoodOrder::FoodOrder(const MenuItem& menuItem)
	:Service("Food Order", menuItem.GetPrice()), m_menuItem(menuItem) {}

MenuItem FoodOrder::GetMenuItem() const
{
	return m_menuItem;
}

void FoodOrder::ExecuteService()	
{
	std::cout << "Food Order: " << m_menuItem.GetName() << " is being prepared and delivered." << std::endl;
}

