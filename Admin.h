#pragma once
#include "Employee.h"
#include "Client.h"
#include <vector>
#include <iostream>
#include <fstream>
#include "FilesHelper.h"

using namespace std;

class Admin : public Employee {
public:
    Admin() : Employee() {}

    Admin(int id,  string name,  string password, double salary)
        : Employee(id, name, password, salary) {
    }

    void displayinfo()  {
        cout << "Admin Information:" << endl;
        Employee::displayinfo();
    }

    void saveToFile();
    void updateLastAdminID();
    void addEmployee(Employee& employee);
    Employee* searchEmployee(int id);
    void listEmployee();
    void editEmployee(int id, string name, string password, double salary);
   
   
};
