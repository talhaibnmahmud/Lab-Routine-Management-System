#include "Admin.h"


const std::string Admin::COORDINATOR_FILE = std::string("coordinator.csv");
const std::string Admin::LAB_FILE = std::string("lab.csv");
const std::string Admin::STUDENT_FILE = std::string("student.csv");

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

	while (true)
	{
		system("CLS");
		std::cout << "1. Create Coordinator" << std::endl;
		std::cout << "2. Create Student" << std::endl;
		std::cout << "3. Go Back" << std::endl;

		int option = 0; 
		std::cin >> option;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		// std::cout << option << std::endl;

		if (option == 3) break;
		if (option == 1) createCoordinator();
		if (option == 2) createStudent();
	}
	// std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void Admin::login()
{
	system("CLS");

	std::string username = "";
	std::string password = "";

	std::cout << "Enter Username: ";
	std::cin >> username;
	std::cout << "Enter Password: ";
	std::cin >> password;

	if (username == USERNAME && password == PASSWORD)
	{
		// std::cout << "LOGGED IN!" << std::endl;
		// std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		adminMenu();
	}
	else {
		std::cout << "Are you sure you entered the correct credentials?" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	}
}

void Admin::createLab()
{
	std::ifstream coordinator_ifs, lab_ifs;
	std::ofstream lab_ofs;

	std::vector<std::string> coordinators;
	std::vector<std::string> labs;


	coordinator_ifs.open(COORDINATOR_FILE, std::ios::in);
	if (coordinator_ifs.is_open())
	{
		std::string line, word, temp;
		while (std::getline(coordinator_ifs, line))
		{
			std::stringstream s(line);

			std::getline(s, word, ',');
			coordinators.push_back(word);
		}
		coordinator_ifs.close();
	}

	lab_ifs.open(LAB_FILE, std::ios::in);
	if (lab_ifs.is_open())
	{
		std::string line, word, temp;
		while (std::getline(lab_ifs, line))
		{
			std::stringstream s(line);

			std::getline(s, word, ',');
			labs.push_back(word);
		}
		lab_ifs.close();
	}

	lab_ofs.open(LAB_FILE, std::ios::out | std::ios::app);
	if (lab_ofs.is_open())
	{
		std::string lab_name = std::string("");
		std::string lab_coordinator = std::string("");

		std::cout << "Enter a unique Lab: ";
		std::cin >> lab_name;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Assign a coordinator: ";
		std::cin >> lab_coordinator;

		if (std::find(coordinators.begin(), coordinators.end(), lab_coordinator) != coordinators.end()
			&& std::find(labs.begin(), labs.end(), lab_name) == labs.end())
		{
			lab_ofs << lab_name << ",";
			lab_ofs << lab_coordinator << std::endl;

			std::cout << "Lab created: " << lab_name << ", Coordinator: " << lab_coordinator << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(3000));
		}
		lab_ofs.close();
	}
}

void Admin::createCoordinator()
{
	std::ofstream fs;
	fs.open(COORDINATOR_FILE, std::ios::app);
	if (fs.is_open())
	{
		std::cout << "Enter username: ";
		std::string username = std::string("");
		std::cin >> username;
		fs << username << ",";

		std::cout << "Enter Password: ";
		std::string password = std::string("");
		std::cin >> password;
		fs << password << std::endl;

		std::cout << "Coordinator created: " << username << std::endl;
		std::this_thread::sleep_for(std::chrono::microseconds(3000));
	}
	fs.close();
}

void Admin::createStudent()
{
	std::ofstream fs;
	fs.open(STUDENT_FILE, std::ios::app);
	if (fs.is_open())
	{
		std::cout << "Enter username: ";
		std::string username = std::string("");
		std::cin >> username;
		fs << username << ",";

		std::cout << "Enter password: ";
		std::string password = std::string("");
		std::cin >> password;
		fs << password << std::endl;

		std::cout << "Student created: " << username << std::endl;
		std::this_thread::sleep_for(std::chrono::microseconds(3000));
	}
	fs.close();
}
