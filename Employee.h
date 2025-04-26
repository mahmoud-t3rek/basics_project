#pragma once
#include "Person.h"
#include <iostream>
#include <fstream>
#include "Client.h"
#include "Validation.h"
class FilesHelper;
class FileManger;

using namespace std;

class Employee : public Person {
protected:
    double salary;

public:
    Employee() : salary(0.0) {}

    Employee(int id,  string name,  string password, double salary)
        : Person(id, name, password), salary(salary) {
    }

    void setSalary(double salary) {
        this->salary = salary;
    }

    double getSalary()  {
        return salary;
    }

    void displayinfo() {
        Person::displayinfo();
        cout << "Salary: " << salary << "$" << endl;
    }
    static void addClient(Client& client);
    static Client* searchClient(int id);
    void saveToFile();
    void updateLastEmployeeID();
    void editClient(int id, string name, string password, double balance);
    void listClient();
  
};

