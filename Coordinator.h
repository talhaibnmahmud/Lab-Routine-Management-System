#pragma once

// #include <set>

#include <algorithm>
#include <array>
#include <fstream>
#include <ios>
#include <iostream>
#include <limits>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include "Device.h"


class Coordinator
{
public:

	void login();
	void menu();

	void addDevice();
	void updateDevice();
	void deleteDevice();
	void makeRoutine();
};
