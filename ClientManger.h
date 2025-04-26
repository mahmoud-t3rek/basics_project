#pragma once
#include "FilesHelper.h"
#include "Client.h"
#include "Employee.h"
#include "FileManager.h"
#include <fstream>
#include <iostream>
#include <vector>
#include "Parser.h"

using namespace std;

class ClientManager {
public:
    static void printClientMenu() {
        cout << "Login successful!\n";
        cout << "1. Update Password\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. Transfer To\n";
        cout << "6. Exit\n";
        cout << "==============================\n";
        cout << "Enter your choice: ";
    }
    static void updatePassword(Person* person) {
        if (!person) {
            cout << "Error: Invalid person pointer!\n";
            return;
        }
        string newPassword = Validation::enterPassword();
        person->setpassword(newPassword);
        cout << "Password updated successfully!\n";
        
    }
    static Client* login(int id, string password) {
        ifstream inFile("Client.txt");
        if (!inFile.is_open()) {
            cout << "Error: Unable to open Client.txt!\n";
            return nullptr;
        }

        string line;
        while (getline(inFile, line)) {
            Client c = Parser::parseToClient(line);
            if (c.getid() == id && c.getpassword() == password) {
                inFile.close();
                return new Client(c);
            }
        }

        inFile.close();
        return nullptr;
    }
    static void clientOptions(Client* client) {
        if (!client) {
            cout << "Error: Invalid client!\n";
            return;
        }

        while (true) {
            printClientMenu();
            int choice;
            cin >> choice;

            double amount;
            int id;
            switch (choice) {
            case 1:
                system("cls");
                updatePassword(client);
                break;
            case 2:
                system("cls");
                cout << "Enter amount to deposit: ";
                cin >> amount;
                client->deposit(amount);
               
                break;
            case 3:
                system("cls");
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                client->withdraw(amount);
              
                break;
            case 4:
                system("cls");
                client->checkBalance();
                break;
            case 5:
                system("cls");
                cout << "Enter id to transfer to: ";
                cin >> id;
                while (Employee::searchClient(id) == nullptr) {
                    cout << "Incorrect ID! Enter a valid ID: ";
                    cin >> id;
                }
                cout << "Enter amount to transfer: ";
                cin >> amount;
                client->transferTo(amount, *Employee::searchClient(id));
                break;
            case 6:
                system("cls");
                cout << "Logging out...\n";
                return;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
            }
        }
    }
};
