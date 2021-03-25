#include "Coordinator.h"


void Coordinator::login()
{
	system("CLS");

	std::map<std::string, std::string> coordinators;
	std::vector<std::string> users;
	std::ifstream fs;
	fs.open("coordinator.csv", std::ios::in);
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

	std::cout << "Enter Username: " << std::endl;
	std::cin >> username;
	std::cout << "Enter Password: " << std::endl;
	std::cin >> password;

	std::map<std::string, std::string>::iterator it = coordinators.find(username);
	if (it == coordinators.end()) return;
	if (it->second != password) return;

	std::cout << "LOGGED IN!" << std::endl;

	menu();
}

void Coordinator::menu()
{
	int choice = 0;

	while (true)
	{
		system("CLS");

		std::cout << "1. Create Device" << std::endl;
		std::cout << "2. Update Device" << std::endl;
		std::cout << "3. Delete Device" << std::endl;
		std::cout << "4. Make Routine" << std::endl;
		std::cout << "5. Logout" << std::endl;

		std::cin >> choice;
		if (choice == 5) return;

		if (choice == 1) addDevice();
		if (choice == 2) updateDevice();
		if (choice == 3) deleteDevice();
		if (choice == 4) makeRoutine();
	}
}

void Coordinator::addDevice()
{
	std::string lab_name = std::string("");
	std::cout << "Enter Lab Name: " << std::endl;
	std::cin >> lab_name;

	std::vector<std::string> labs;
	std::ifstream fs;
	fs.open("lab.csv", std::ios::app);
	if (fs.is_open())
	{
		std::string line, word;
		while (std::getline(fs, line))
		{
			std::stringstream s(line);

			std::getline(s, word, ',');
			labs.push_back(word);
		}
		fs.close();
	}

	if (std::find(labs.begin(), labs.end(), lab_name) == labs.end()) return;

	Device device;
	char status;
	std::cout << "Enter Device Name: ";
	std::cin >> device.name;
	std::cout << "Enter Device Status (Y/N): ";
	std::cin >> status;

	if (status == 'n' || status == 'N') device.status = false;

	std::fstream ofs;
	ofs.open(lab_name + ".csv", std::ios::app);
	if (ofs.is_open())
	{
		ofs << device.name << ",";
		ofs << device.status << std::endl;
	}
}

void Coordinator::updateDevice()
{
	std::string lab_name = std::string("");
	std::cout << "Enter Lab Name: " << std::endl;
	std::cin >> lab_name;

	std::vector<std::string> labs;
	std::ifstream fs;
	fs.open("lab.csv", std::ios::app);
	if (fs.is_open())
	{
		std::string line, word;
		while (std::getline(fs, line))
		{
			std::stringstream s(line);

			std::getline(s, word, ',');
			labs.push_back(word);
		}
		fs.close();
	}

	if (std::find(labs.begin(), labs.end(), lab_name) == labs.end()) return;

	std::string lab_file = lab_name + ".csv";
	char* lab_file_name = &*lab_file.begin();

	Device device;
	char status = 'y';

	std::cout << "Enter Device Name: ";
	std::cin >> device.name;
	std::cout << "Enter Device Status (Y/N): ";
	std::cin >> status;

	device.status = (status == 'n' || status == 'N') ? false : true;

	std::ifstream ifs;
	std::ofstream ofs;

	ifs.open(lab_name + ".csv", std::ios::in);
	ofs.open("temp.csv", std::ios::out);

	std::vector<std::string> row;
	if (ifs.is_open() && ofs.is_open())
	{
		std::string line, word;
		while (std::getline(ifs, line))
		{
			row.clear();
			std::stringstream s(line);

			while (std::getline(s, word, ','))
			{
				row.push_back(word);
			}

			if (device.name == row[0])
			{
				ofs << device.name << ",";
				ofs << device.status << std::endl;
				continue;
			}

			ofs << row[0] << ",";
			ofs << row[1] << std::endl;
		}
		ifs.close();
		ofs.close();

		remove(lab_file_name);
		int success = rename("temp.csv", lab_file_name);
	}
}

void Coordinator::deleteDevice()
{
	std::string lab_name = std::string("");
	std::cout << "Enter Lab Name: " << std::endl;
	std::cin >> lab_name;

	std::vector<std::string> labs;
	std::ifstream fs;
	fs.open("lab.csv", std::ios::app);
	if (fs.is_open())
	{
		std::string line, word;
		while (std::getline(fs, line))
		{
			std::stringstream s(line);

			std::getline(s, word, ',');
			labs.push_back(word);
		}
		fs.close();
	}

	if (std::find(labs.begin(), labs.end(), lab_name) == labs.end()) return;

	std::string lab_file = lab_name + ".csv";
	char* lab_file_name = &*lab_file.begin();

	Device device;

	std::cout << "Enter Device Name: ";
	std::cin >> device.name;

	std::ifstream ifs;
	std::ofstream ofs;

	ifs.open(lab_name + ".csv", std::ios::in);
	ofs.open("temp.csv", std::ios::out);

	std::vector<std::string> row;
	if (ifs.is_open() && ofs.is_open())
	{
		std::string line, word;
		while (std::getline(ifs, line))
		{
			row.clear();
			std::stringstream s(line);

			while (std::getline(s, word, ','))
			{
				row.push_back(word);
			}

			if (device.name == row[0]) continue;

			ofs << row[0] << ",";
			ofs << row[1] << std::endl;
		}
		ifs.close();
		ofs.close();

		remove(lab_file_name);
		int success = rename("temp.csv", lab_file_name);
	}
}

void Coordinator::makeRoutine()
{
	std::string lab_name = std::string("");
	std::cout << "Enter Lab Name: " << std::endl;
	std::cin >> lab_name;

	std::vector<std::string> labs;
	std::ifstream fs;
	fs.open("lab.csv", std::ios::app);
	if (fs.is_open())
	{
		std::string line, word;
		while (std::getline(fs, line))
		{
			std::stringstream s(line);

			std::getline(s, word, ',');
			labs.push_back(word);
		}
		fs.close();
	}

	if (std::find(labs.begin(), labs.end(), lab_name) == labs.end()) return;

	std::array<std::string, 5> routines;
	for (int i = 0; i < routines.size(); i++)
	{
		std::cout << "Enter Day " << i + 1 << ": ";
		std::cin >> routines[i];
	}


	std::ifstream ifs;
	std::ofstream ofs;

	ifs.open("lab.csv", std::ios::in);
	ofs.open("temp.csv", std::ios::out);

	std::vector<std::string> row;
	if (ifs.is_open() && ofs.is_open())
	{
		std::string line, word;
		while (std::getline(ifs, line))
		{
			row.clear();
			std::stringstream s(line);

			while (std::getline(s, word, ','))
			{
				row.push_back(word);
			}

			if (lab_name == row[0])
			{
				ofs << row[0] << ",";
				ofs << row[1] << ",";

				for (std::string day : routines) ofs << day << ",";
				ofs << std::endl;
				continue;
			}

			ofs << row[0] << ",";
			ofs << row[1] << std::endl;
		}
		ifs.close();
		ofs.close();

		remove("lab.csv");
		int success = rename("temp.csv", "lab.csv");
	}
}
