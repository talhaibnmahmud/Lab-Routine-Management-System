// #include<iostream>

#include "Admin.h";
#include "Coordinator.h";
#include "Device.h";
#include "Student.h";

int main()
{
	Admin admin;
	admin.createAccount();
	admin.createLab();

	Coordinator coordinator;
	coordinator.addDevice();
	coordinator.deleteDevice();
	coordinator.makeRoutine();
	coordinator.updateDevice();

	Device device;
	device.createDevice();
	device.deleteDevice();
	device.updateDevice();

	Student student;
	student.getRoutine();
}
