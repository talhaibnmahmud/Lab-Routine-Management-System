#pragma once

#include <iostream>

class Device
{
public:
	Device() 
	{
		std::cout << "Device Instantiated\n";
	}

	void createDevice();
	void updateDevice();
	void deleteDevice();
};
