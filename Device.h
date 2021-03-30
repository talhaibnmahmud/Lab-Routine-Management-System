#pragma once

#include <iostream>

class Device
{
public:
	std::string name = std::string("");
	bool status = true;
	void createDevice();
	void updateDevice();
	void deleteDevice();
};
