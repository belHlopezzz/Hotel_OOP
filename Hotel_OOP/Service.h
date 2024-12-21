#pragma once
#include <string>
class Service
{
private:
	std::string m_seriveName;
	float m_price;

public:
    Service(const std::string& serviceName, float price);

    virtual void ExecuteService() = 0;  
    float GetPrice() const; 
    std::string GetServiceName() const; 

    virtual ~Service() {}
};

