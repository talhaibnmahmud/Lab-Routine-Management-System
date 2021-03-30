#include "Control.h"

void Control::mainMenu()
{
	system("color 3f");

	enum Options
	{
		Exit, Admin, Coordinator, Student
	};
	int16_t choice = 0;

	while (true)
	{
		system("CLS");

		std::cout << "Welcome to Lab Routine Management System!" << std::endl;
		std::cout << std::endl << std::endl << std::endl;

		std::cout << "1. Login as Admin" << std::endl;
		std::cout << "2. Login as Coordinator" << std::endl;
		std::cout << "3. Login as Student" << std::endl;
		std::cout << "0. Exit" << std::endl;

		std::cin >> choice;
		std::cin.ignore();

		if (choice == Exit) exit(0);

		if (choice == Admin) handleAdmin();
		if (choice == Coordinator) handleCoordinator();
		if (choice == Student) handleStudent();
	}
}

void Control::handleAdmin()
{
	Admin admin;
	enum Options
	{
		MainMenu, Login
	};
	int16_t choice = 0;

	while (true)
	{
		system("CLS");

		std::cout << "1. Login as Admin" << std::endl;
		std::cout << "0. Main Menu" << std::endl;

		std::cin >> choice;
		std::cin.ignore();

		if (choice == MainMenu) return;
		if (choice == Login) admin.login();
	}
}

void Control::handleCoordinator()
{
	Coordinator coordinator;
	int16_t choice = 0;
	while (true)
	{
		system("CLS");

		std::cout << "1. Login as Coordinator" << std::endl;
		std::cout << "0. Main Menu" << std::endl;
		std::cin >> choice;

		if (choice == 0) return;
		if (choice == 1) coordinator.login();
	}
}

void Control::handleStudent()
{
	Student student;
	int16_t choice = 0;
	while (true)
	{
		system("CLS");

		std::cout << "1. Login as Student" << std::endl;
		std::cout << "0. Main Menu" << std::endl;
		std::cin >> choice;

		if (choice == 0) return;
		if (choice == 1) student.login();
	}
}
