#pragma once

#include <algorithm>
#include <chrono>
#include <fstream>
#include <ios>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

class Admin
{
	static const std::string COORDINATOR_FILE;
	static const std::string LAB_FILE;
	static const std::string STUDENT_FILE;

	void createCoordinator();
	void createStudent();
public:
	static const std::string USERNAME;
	static const std::string PASSWORD;

	void adminMenu();
	void createAccount();
	void createLab();
	void login();
};

