#pragma once
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include <vector>
#include <sstream>

using namespace std;

class Parser {
public:
    static vector<string> split(string line) {
        vector<string> parts;
        stringstream ss(line);
        string part;

        while (getline(ss, part, '&')) {
            parts.push_back(part);
        }
        return parts;
    }

    static Client parseToClient(string line) {
        vector<string> parts = split(line);
      
        int id = stoi(parts[0]);
        string name = parts[1];
        string password = parts[2];
        double balance = stod(parts[3]);

        return Client(id, name, password, balance);
    }

    static Employee parseToEmployee(string line) {
        vector<string> parts = split(line);
       
        int id = stoi(parts[0]);
        string name = parts[1];
        string password = parts[2];
        double salary = stod(parts[3]);

        return Employee(id, name, password, salary);
    }

    static Admin parseToAdmin(string line) {
        vector<string> parts = split(line);
        
        int id = stoi(parts[0]);
        string name = parts[1];
        string password = parts[2];
        double salary = stod(parts[3]);
        return Admin(id, name, password, salary);
        
    }
};