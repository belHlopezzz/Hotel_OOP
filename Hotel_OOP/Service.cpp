#include "Service.h"

Service::Service(const std::string& serviceName, float price)
    : m_seriveName(serviceName), m_price(price) {}

float Service::GetPrice() const
{
    return m_price;
}

std::string Service::GetServiceName() const
{
    return m_seriveName; 
}


