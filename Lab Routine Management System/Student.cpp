#include "Student.h"

void Student::login()
{
	system("CLS");

	std::map<std::string, std::string> coordinators;
	std::vector<std::string> users;
	std::ifstream fs;
	fs.open("student.csv", std::ios::in);
	if (fs.is_open())
	{
		std::string line, word;
		while (std::getline(fs, line))
		{
			users.clear();
			std::stringstream s(line);
			while (std::getline(s, word, ','))
			{
				users.push_back(word);
			}

			coordinators.insert({ users[0], users[1] });
		}
		fs.close();
	}

	std::string username = "";
	std::string password = "";

	std::cout << "Enter Username: ";
	std::cin >> username;
	std::cout << "Enter Password: ";
	std::cin >> password;

	std::map<std::string, std::string>::iterator it = coordinators.find(username);
	if (it == coordinators.end()) return;
	if (it->second != password) return;

	std::cout << "LOGGED IN!" << std::endl;

	menu();
}

void Student::menu()
{
	int choice = 0;

	while (true)
	{
		system("CLS");

		std::cout << "1. Check Routine" << std::endl;
		std::cout << "2. Check Devices" << std::endl;
		std::cout << "3. Logout" << std::endl;

		std::cin >> choice;
		if (choice == 3) return;

		if (choice == 1) getRoutine();
		if (choice == 2) getDevices();
	}
}

void Student::getRoutine()
{
	std::string lab_name = std::string("");
	std::cout << "Enter Lab Name: " << std::endl;
	std::cin >> lab_name;

	std::vector<std::string> row;
	std::ifstream fs;
	fs.open("lab.csv", std::ios::in);
	if (fs.is_open())
	{
		std::string line, word;
		while (std::getline(fs, line))
		{
			row.clear();
			std::stringstream s(line);

			while(std::getline(s, word, ',')) row.push_back(word);

			if (row[0] == lab_name)
			{
				if (row.size() < 3)
				{
					std::cout << "No Routine Assigned!" << std::endl;
					break;
				}

				for (int i = 2; i < row.size(); i++)
				{
					std::cout << "Day " << i - 1 << ": " << row[i] << std::endl;
				}
			}
		}
		fs.close();
	}

	std::cin.ignore();
	std::cin.get();
}

void Student::getDevices()
{
	std::string lab_name = std::string("");
	std::cout << "Enter Lab Name: " << std::endl;
	std::cin >> lab_name;

	std::string lab_file = lab_name + ".csv";
	char* lab_file_name = &*lab_file.begin();

	std::vector<std::string> row;
	std::ifstream fs;
	fs.open(lab_file_name, std::ios::in);
	if (fs.is_open())
	{
		std::string line, word;
		while (std::getline(fs, line))
		{
			row.clear();
			std::stringstream s(line);
			std::string status;

			while (std::getline(s, word, ',')) row.push_back(word);

			status = (row[1] == "1") ? "OK" : "Not OK";
			std::cout << "Device Name: " << row[0] << ", " << "Status: " << status << std::endl;
		}
		fs.close();
	}

	std::cin.ignore();
	std::cin.get();
}
