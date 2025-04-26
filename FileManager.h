#pragma once
#include "FilesHelper.h"
#include "Client.h"
#include"Validation.h"
#include "Employee.h"
#include <fstream>
#include <iostream>
#include <vector>
#include "Parser.h"
class FileManager
{
public:
    static void addClient() {

        int id = FilesHelper::getLast("LastClientID.txt");
        if (id == -1) id = 1;
        else id++;


        string  name = Validation::entername();
        string  password = Validation::enterPassword();
        double  balance = Validation::valid_balance();

        Client newClient(id, name, password, balance);
        ofstream file("client.txt", ios::app);
        if (file.is_open()) {
            file << id << "&" << name << "&" << password << "&" << balance << "\n";
            file.close();
            cout << "Client added successfully!\n";
        }
        else {
            cout << "Error opening file!\n";
        }
        FilesHelper::saveLast("LastClientID.txt", id);
    }
    static void addEmployee() {
        int id = FilesHelper::getLast("LastEmployeeID.txt");
        if (id == -1) id = 1;
        else id++;
        string  name = Validation::entername();
        string  password = Validation::enterPassword();
        double  salary = Validation::valid_salary();
        Employee newClient(id, name, password, salary);
        ofstream file("Employee.txt", ios::app);
        if (file.is_open()) {
            file << id << "&" << name << "&" << password << "&" << salary << "\n";
            file.close();
            cout << "Employee added successfully!\n";
        }
        else {
            cout << "Error opening file!\n";
        }
        FilesHelper::saveLast("LastEmployeeID.txt", id);
    }
    static void addadmin() {
        int id = FilesHelper::getLast("LastAdminID.txt");
        if (id == -1) id = 1;
        else id++;

        string  name = Validation::entername();
        string  password = Validation::enterPassword();
        double  salary = Validation::valid_salary();

        Admin newClient(id, name, password, salary);
        ofstream file("Admin.txt", ios::app);
        if (file.is_open()) {
            file << id << "&" << name << "&" << password << "&" << salary << "\n";
            file.close();
            cout << "Admin added successfully!\n";
        }
        else {
            cout << "Error opening file!\n";
        }
        FilesHelper::saveLast("LastAdminID.txt", id);

    }
    static void getAllClients() {
        FilesHelper::getClients();
    }
    static void getAllEmployee() {
        FilesHelper::getEmployees();
    }
    static void getAllAdmin() {
        FilesHelper::getAdmins();
    }
    static void removeAllClients() {
        FilesHelper::clearFile("Client.txt", "LastClientID.txt");
    }
    static void removeAllEmployees() {
        FilesHelper::clearFile("Employee.txt", "LastEmployeeID.txt");
    }
    static void removeAllAdmins() {
        FilesHelper::clearFile("Admin.txt", "LastAdminID.txt");
    }


    static void editClient() {
        ifstream inFile("Client.txt");
        if (!inFile.is_open()) {
            cout << "Error: Unable to open Client.txt for reading!" << endl;
            return;
        }

        vector<Client> clients;
        string line;
        cout << "Enter your ID to update: ";
        int id;
        cin >> id;

        bool found = false;
        while (getline(inFile, line)) {
            Client c = Parser::parseToClient(line);

            if (c.getid() == id) {
                cout << "Client found. Enter new details:\n";
                c.setname(Validation::entername());
                c.setpassword(Validation::enterPassword());
                c.setBalance(Validation::valid_balance());
                found = true;
            }

            clients.push_back(c);
        }
        inFile.close();

        if (!found) {
            cout << "Error: Client with ID " << id << " not found!" << endl;
            return;
        }

        ofstream outFile("Client.txt", ios::trunc);
        if (!outFile.is_open()) {
            cout << "Error: Unable to open Client.txt for writing!" << endl;
            return;
        }

        for (size_t i = 0; i < clients.size(); i++) {
            outFile << clients[i].getid() << '&'
                << clients[i].getname() << '&'
                << clients[i].getpassword() << '&'
                << clients[i].getBalance() << endl;
        }

        outFile.close();
        cout << "Client updated successfully!" << endl;
    }
    static void editEmployee() {
        ifstream inFile("Employee.txt");
        if (!inFile.is_open()) {
            cout << "Error: Unable to open Employee.txt for reading!" << endl;
            return;
        }

        vector<Employee> employees;
        string line;
        cout << "Enter your ID to update: ";
        int id;
        cin >> id;

        bool found = false;
        while (getline(inFile, line)) {
            Employee c = Parser::parseToEmployee(line);

            if (c.getid() == id) {
                cout << "Employee found. Enter new details:\n";
                c.setname(Validation::entername());
                c.setpassword(Validation::enterPassword());
                c.setSalary(Validation::valid_salary());
                found = true;
            }

            employees.push_back(c);
        }
        inFile.close();

        if (!found) {
            cout << "Error: Employee with ID " << id << " not found!" << endl;
            return;
        }

        ofstream outFile("Employee.txt", ios::trunc);
        if (!outFile.is_open()) {
            cout << "Error: Unable to open Employee.txt for writing!" << endl;
            return;
        }

        for (size_t i = 0; i < employees.size(); i++) {
            outFile << employees[i].getid() << '&'
                << employees[i].getname() << '&'
                << employees[i].getpassword() << '&'
                << employees[i].getSalary() << endl;
        }

        outFile.close();
        cout << "Employee updated successfully!" << endl;
    }
    static void getData() {
        getAllAdmin();
        getAllEmployee();
        getAllClients();
    }
  

};

