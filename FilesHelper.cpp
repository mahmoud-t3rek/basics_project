#pragma once
#include "FilesHelper.h"
#include "Client.h"
#include "Employee.h"
#include <fstream>
#include <iostream>
#include <vector>
#include "Parser.h"

 void  FilesHelper::saveLast(string fileName, int id) {
    ofstream file(fileName, ios::trunc);
    if (file.is_open()) {
        file << id << endl;
        file.close();
    }
    else {
       cout << "Error: Unable to open file " << fileName << " for writing last ID." << endl;
    }
}
 int FilesHelper::getLast(string fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
       cout << "Error: Unable to open file " << fileName << " for reading last ID." << endl;
        return -1;
    }

    int lastId = -1, temp;
    while (file >> temp) {
        lastId = temp;
    }
    file.close();
    return lastId;
}

 void FilesHelper::saveClient(Client c) {
     ofstream file("Clients.txt", ios::app);
     if (file) {
         file << c.getid() << '&' << c.getname() << '&' << c.getpassword() << '&' << c.getBalance() << endl;
         file.close();

         FilesHelper::saveLast("LastClientID.txt", c.getid());
     }
     else {
         cout << "Error: Unable to open file for saving client!" << endl;
     }
 }
 void FilesHelper::saveEmployee( Employee e) {
     ofstream file("Employee.txt", ios::app);
     if (file) {
         file << e.getid() << '&' << e.getname() << '&' << e.getpassword() << '&' << e.getSalary() << endl;
         file.close();

         FilesHelper::saveLast("LastEmployeeID.txt", e.getid());
     }
     else {
         cout << "Error: Unable to open file for saving Employee!" << endl;
     }
 }

 vector<Client> FilesHelper::clients;
 void FilesHelper::getClients() {
     ifstream file("Client.txt");
     if (!file.is_open()) {
         cerr << "Error: Unable to open Clients.txt for reading!" << endl;
         return;
     }

     string line;
     clients.clear();

     while (getline(file, line)) {
             Client c = Parser::parseToClient(line);
             clients.push_back(c);
         
     }
     file.close();

     if (clients.empty()) {
         cout << "No clients found." << endl;
         return;
     }


     cout << "-------- Client List --------" << endl;
     for (size_t i = 0; i < clients.size(); i++) {
         cout << "ID: " << clients[i].getid() << endl
             << "Name: " << clients[i].getname() << endl
             << "Balance: " << clients[i].getBalance() << endl <<
             "Passward: " << clients[i].getpassword() << endl;
         cout << "---------------------" << endl;
     }
 }
        
     
 
 vector<Employee> FilesHelper::employee;
 void FilesHelper::getEmployees() {
     ifstream file("Employee.txt");
     if (!file.is_open()) {
         cout << "Error: Unable to open Employee.txt for reading!" << endl;
         return;
     }

     string line;
     employee.clear();


     while (getline(file, line)) {
            Employee c = Parser::parseToEmployee(line);
             employee.push_back(c);
     }
     file.close();

     if (employee.empty()) {
         cout << "No employees found." << endl; 
         return;
     }

     cout << "-------- Employee List --------" << endl;

     for (size_t i = 0; i < employee.size(); i++) {
         cout << "ID: " << employee[i].getid() << endl
             << "Name: " << employee[i].getname() << endl
             << "Balance: " << employee[i].getSalary() << endl <<
             "Passward: " << employee[i].getpassword() << endl;
         cout << "---------------------" << endl;
     }
 }

 void FilesHelper::getAdmins() {
     ifstream file("Admin.txt");
     if (!file.is_open()) {
         cout << "Error: Unable to open Admins.txt for reading!" << endl;
         return;
     }

     string line;
     vector<Admin> admins; 

     while (getline(file, line)) {
         if (line.empty())
             continue; 

             Admin admin = Parser::parseToAdmin(line);
             admins.push_back(admin);
         
         
     }

     file.close();

    
     for (int i = 0; i < admins.size(); i++) {
         cout << "ID: "<< admins[i].getid() << endl <<"Name: "<<
             admins[i].getname() << endl<<"Password: " << admins[i].getpassword() << endl
           << "Salary: " << admins[i].getSalary() << endl;
         cout << "-------------------------" << endl;

     }
 }
 void FilesHelper::clearFile(string fileName, string lastIdFile) {
     ofstream file1(fileName, ios::trunc);
     ofstream file2(lastIdFile, ios::trunc);

     if (!file1 || !file2) {
         cout << "Error: Unable to clear files!" << endl;
         return;
     }

     file2 << 0;
     cout << "Clear successfully" << endl;
 }



