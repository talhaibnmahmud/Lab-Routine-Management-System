#pragma once

// #include <iostream>
#include <Windows.h>

#include "Admin.h"
#include "Coordinator.h"
#include "Student.h"

class Control
{
public:
	void mainMenu();
	void handleAdmin();
	void handleCoordinator();
	void handleStudent();
};

