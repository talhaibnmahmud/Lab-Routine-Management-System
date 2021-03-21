#pragma once

#include <iostream>

class Coordinator
{
public:
	Coordinator() 
	{
		std::cout << "Coordinator Instantiated\n";
	}

	void addDevice();
	void updateDevice();
	void deleteDevice();
	void makeRoutine();
};
