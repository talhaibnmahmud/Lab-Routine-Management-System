#pragma once

#include <iostream>

class Student
{
public:
	Student() 
	{
		std::cout << "Student Instantiated\n";
	}

	void getRoutine();
};
