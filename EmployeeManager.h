#pragma once
#include "FilesHelper.h"
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

class EmployeeManger {
public:
    static void printEmployeMenu() {

            cout << "Login successful!\n";
            cout << "1. Update Password\n";
            cout << "2. View All Clients\n";
            cout << "3. Add New Client\n";
            cout << "4. Edit Client\n";
            cout << "5. Search for client\n";
            cout << "6. Exit\n";
            cout << "==============================\n";
            cout << "Enter your choice: ";
        
    }
  static void newClient(Employee* employee) {
        if (employee == nullptr) {
            cout << "Error: Invalid employee pointer!\n";
            return;
        }
        FileManager::addClient(); 
  }
  static void listAllClients(Employee* employee) {
      FilesHelper::getClients();
  }
  static void searchForClient(Employee* employee) {
      if (employee == nullptr) {
          cout << "Error: Invalid employee pointer!\n";
          return;
      }

      cout << "Enter Client ID to search: ";
      int id;
      cin >> id;

      Client* client = employee->searchClient(id);

      if (client == nullptr) {
          cout << "Client not found!\n";
      }
      
          delete client;
  }
  static void editClientInfo(Employee* employee) {
      if (employee == nullptr) {
          cout << "Error: Invalid employee\n";
          return;
      }

      cout << "Editing client information\n";
      FileManager::editClient();
  }
  static Employee* login(int id, string password) {
      ifstream inFile("Employee.txt");
      if (!inFile.is_open()) {
          cout << "Error: Unable to open Employee.txt!" << endl;
          return nullptr;
      }

      string line;
      while (getline(inFile, line)) {
          Employee c = Parser::parseToEmployee(line);
          if (c.getid() == id && c.getpassword() == password) {
              inFile.close();
              return new Employee(c);
          }
      }

      inFile.close();
      cout << "Invalid ID or password!" << endl;
      return nullptr;
  }
  static void employeeOptions(Employee* employee) {
      if (employee == nullptr) {
          cout << "Error: Invalid Employee!" << endl;
          return;
      }

      while (true) {
      printEmployeMenu();
      int choice;
      cin>>choice;
      system("cls");
      switch (choice) {
   
      case 1:
          ClientManager::updatePassword(employee);
          system("pause");
          break;
      case 2:
          FilesHelper::getClients();
          system("pause");
          break;
      case 3:
          newClient(employee);
          system("pause");
          break;
      case 4:
          FileManager::editClient();
          system("pause");
          break;
      case 5:
          searchForClient(employee);
          system("pause");
          break;
      case 6:
          cout << "Logging out\n";
          return;
      default:
          cout << "Invalid choice! Please try again.\n";
          employeeOptions(employee);
          system("pause");
          return;
      }
      }
  }

};
