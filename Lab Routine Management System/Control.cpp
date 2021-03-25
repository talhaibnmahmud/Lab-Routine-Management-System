#include "Control.h"

void Control::mainMenu()
{
	system("CLS");
	system("color 3f");

	std::cout << "Welcome to Lab Routine Management System!" << std::endl;
	std::cout << std::endl << std::endl << std::endl;

	std::cout << "1. Login as Admin" << std::endl;
	std::cout << "2. Login as Coordinator" << std::endl;
	std::cout << "3. Login as Student" << std::endl;
	std::cout << "4. Exit" << std::endl;

	int choice = 0;
	std::cin >> choice;
	std::cin.get();

	switch (choice)
	{
	case 1:
		std::cout << choice << std::endl;
		handleAdmin();
		break;
	case 2:
		std::cout << choice << std::endl;
		handleCoordinator();
		break;
	case 3:
		std::cout << choice << std::endl;
		handleStudent();
		break;
	case 4:
		exit(0);
		break;
	default:
		std::cout << choice << std::endl;
		break;
	}
}

void Control::handleAdmin()
{
	system("CLS");

	std::cout << "1. Login as Admin" << std::endl;
	std::cout << "2. Main Menu" << std::endl;

	Admin admin;
	int choice = 0;
	std::cin >> choice;

	switch (choice)
	{
	case 1:
		std::cout << choice << std::endl;
		std::cin.get();
		admin.login();
		break;
	case 2:
		return;
		break;
	default:
		std::cout << choice << std::endl;
		break;
	}
}

void Control::handleCoordinator()
{
	Coordinator coordinator;
	int choice = 0;
	while (true)
	{
		system("CLS");

		std::cout << "1. Login as Coordinator" << std::endl;
		std::cout << "2. Main Menu" << std::endl;
		std::cin >> choice;

		if (choice == 2) return;
		if (choice == 1) coordinator.login();
	}
}

void Control::handleStudent()
{
	Student student;
	int choice = 0;
	while (true)
	{
		system("CLS");

		std::cout << "1. Login as Student" << std::endl;
		std::cout << "2. Main Menu" << std::endl;
		std::cin >> choice;

		if (choice == 2) return;
		if (choice == 1) student.login();
	}
}
