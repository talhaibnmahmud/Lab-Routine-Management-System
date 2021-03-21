#pragma once

#include <chrono>
#include <iostream>
#include <string>
#include <thread>

class Admin
{
public:
	static const std::string USERNAME;
	static const std::string PASSWORD;

	void adminMenu();
	void createAccount();
	void createLab();
	void login();
};

