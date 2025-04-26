#pragma once
#include "Client.h"
#include "Employee.h"
#include "FileManager.h"
#include "Validation.h"
#include <fstream>
#include <iostream>
#include <vector>
#include "Parser.h"
#include "ClientManger.h"
#include "Admin.h"
#include "EmployeeManager.h"
class AdminManger
{
public:
    static void printAdminMenu() {
        cout << "1. View All Clients\n";
        cout << "2. Update Password\n";
        cout << "3. Add New Client\n";
        cout << "4. Edit Client\n";
        cout << "5. Search for client\n";
        cout << "6. View All Employees\n";
        cout << "7. Add New Employee\n";
        cout << "8. Edit Employee\n";
        cout << "9. Exit\n";
        cout << "==============================\n";
        cout << "Enter your choice: ";




    }
    static Admin* login(int id, string password) {
        ifstream inFile("Admin.txt");
        if (!inFile.is_open()) {
            cout << "Error: Unable to open Admin.txt!" << endl;
            return nullptr;
        }

        string line;
        while (getline(inFile, line)) {
            Admin c = Parser::parseToAdmin(line);
            if (c.getid() == id && c.getpassword() == password) {
                inFile.close();
                return new Admin(c);
            }
        }

        inFile.close();
        return nullptr;

    }
    static void AdminOptions(Admin* admin) {
       
        if (admin == nullptr) {
            cout << "Error: Invalid client!" << endl;
            return;
        }
        while (true) {
        printAdminMenu();
        Employee e;
        int choice, id;
        cin >> choice;
        system("cls");
        switch (choice) {
        case 1:
           
            FilesHelper::getClients();
            system("pause");
            break;
        case 2:  
            ClientManager::updatePassword(admin);
            system("pause");
            break;
        case 3:
            FileManager::addClient();
            system("pause");
            break;
        case 4:
           
            FileManager::editClient();
            system("pause");
            break;
        case 5:
          
            EmployeeManger::searchForClient(admin);
            system("pause");
            break;
        case 6:
           
            FilesHelper::getEmployees();
            system("pause");
            break;
        case 7:
           
            admin->addEmployee(e);
            system("pause");
            break;
        case 8:
           
            FileManager::editEmployee();
            system("pause");
            break;
        case 9:
            cout << "Logging out\n";
            return;

        default:
            cout << "Invalid choice! Please try again.\n";
            AdminOptions(admin);
            system("pause");
            return;
        }
        system("cls");

        }
    }
};
