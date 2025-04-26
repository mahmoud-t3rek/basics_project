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
#include <windows.h>
#include "AdminManger.h"
#include "EmployeeManager.h"

class Screens
{
public:
	static void bankName() {
       
        cout << "\t\t@@   @@  @@@@@@@  @@@@@@@      ##########     ###########   ######       ##    ###      ###  " << endl;
        cout << "\t\t@@@  @@  @@       @@   @@      ##        ##   ##       ##   ##    ##     ##    ###    ###  " << endl;
        cout << "\t\t@@@@ @@  @@       @@   @@      ##        ##   ##       ##   ##     ##    ##    ###   ###   " << endl;
        cout << "\t\t@@ @@@@  @@@@@@@  @@   @@      ###########    ###########   ##      ##   ##    ### ##     " << endl;
        cout << "\t\t@@  @@@  @@       @@   @@      ##        ##   ##       ##   ##       ##  ##    ###   ###   " << endl;
        cout << "\t\t@@   @@  @@       @@   @@      ##        ##   ##       ##   ##        ## ##    ###    ###   " << endl;
        cout << "\t\t@@   @@  @@@@@@@  @@@@@@@      ##########     ##       ##   ##         ###     ###     ###  " << endl;
        
    }
    static void welcome() {
        system("Color 0E");
        cout << "\n\n\n\n\t    ##             ##   #######    ##          #######     ##########    #####          #####  ######## "<< endl;
        cout << "\t    ##      ##     ##   ##         ##          ##          ##      ##    ###  ##      ## ###   ##         "<<endl;
        cout << "\t    ##     ####    ##   ##         ##          ##          ##      ##    ###   ##    ##  ###   ##         "<<endl;
        cout << "\t    ##    ##  ##   ##   ########   ##          ##          ##      ##    ###    ##  ##   ###   ########   "<< endl;
        cout << "\t    ##   ##    ##  ##   ##         ##          ##          ##      ##    ###     ####    ###   ##         "<< endl;
        cout << "\t    ##  ##      ## ##   ##         ##          ##          ##      ##    ###             ###   ##         "<< endl;
        cout << "\t    ####         ####   ########   ##########  ########    ##########    ###             ###   ########\n\n\n\ "<< endl;
        bankName();
        Sleep(3000);
        system("cls");
        system("Color 0E");
    } 
    static void loginOptions() {
        cout << "(1) ADMIN" << endl;
        cout << "(2) EMPLOYEE" << endl;
        cout << "(3) CLIENT" << endl;
       
    }
    static int loginAs() {
        loginOptions();
        int choice;
        cout << "\nLogin as: ";
        cin >> choice;
        system("cls");
        if (choice == 1 || choice == 2 || choice == 3) {
            return choice;
        }
        else {
            return loginAs();
        }
    }
    static void invalid() {
        cout << "Invalid ID or password!\n";
        system("cls");
        loginScreen(loginAs());
    }
    static void logout() {
        system("cls");
        loginScreen(loginAs());
    }
    static void loginScreen(int c) {
        int id;
        string pass;
        cout << "Enter your ID: ";
        cin >> id;
        cout << "Enter your password: ";
        cin >> pass;
        system("cls");

        switch (c) {
        case 1:
            if (AdminManger::login(id, pass)) {
                AdminManger::AdminOptions(AdminManger::login(id, pass));
                logout();
            }
            else invalid();
            break;
        case 2:
            if (EmployeeManger::login(id, pass)) {
                EmployeeManger::employeeOptions(EmployeeManger::login(id, pass));
                logout();
            }
            else invalid();
            break;
        case 3:
            if (ClientManager::login(id, pass)) {
                ClientManager::clientOptions(ClientManager::login(id, pass));
                logout();
            }
            else invalid();
            break;
        default:
            loginOptions();
        }
    }
    static void runApp() {
        welcome();
        loginScreen(loginAs());
    }
};




