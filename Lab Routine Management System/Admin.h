#pragma once

#include <iostream>

class Admin
{
public:
	Admin() 
	{
		std::cout << "Admin Instantiated\n";
	}

	void createAccount();
	void createLab();
};

