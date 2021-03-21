#include "Admin.h"


const std::string Admin::USERNAME = std::string("admin");
const std::string Admin::PASSWORD = std::string("@dmin@U$T");


void Admin::adminMenu()
{
	system("CLS");

	std::cout << "1. Create Account" << std::endl;
	std::cout << "2. Create Lab" << std::endl;
	std::cout << "3. Logout" << std::endl;

	int choice = 0;
	std::cin >> choice;

	switch (choice)
	{
	case 1:
		std::cout << choice << std::endl;
		std::cin.get();
		createAccount();
		break;
	case 2:
		std::cout << choice << std::endl;
		std::cin.get();
		createLab();
		break;
	case 3:
		return;
	default:
		std::cout << choice << std::endl;
		break;
	}
}

void Admin::createAccount()
{
	std::cout << "Creating New Account" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void Admin::createLab()
{
	std::cout << "Creating New Lab" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void Admin::login()
{
	system("CLS");

	std::string username = "";
	std::string password = "";

	std::cout << "Enter Username: " << std::endl;
	std::cin >> username;
	std::cout << "Enter Password: " << std::endl;
	std::cin >> password;

	if (username == USERNAME && password == PASSWORD)
	{
		//std::cout << "LOGGED IN!" << std::endl;
		//std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		adminMenu();
	}
	else {
		std::cout << "Are you sure you entered the correct credentials?" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
	// std::cout << username << " " << password << std::endl;
	// std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}
