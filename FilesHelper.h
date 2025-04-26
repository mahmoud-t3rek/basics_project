#pragma once
#include <vector>
#include <string>
#include "Client.h"
#include "Employee.h"

using namespace std;

class FilesHelper {
public:
    static void getClients();
    static void getEmployees();
    static void getAdmins();
    static void clearFile(string fileName, string lastIdFile);
    static void saveLast(string fileName, int id);
    static int getLast(string fileName);
    static void saveClient(Client c);
    static void saveEmployee(Employee e);
    static vector<Employee> employee;
    static vector<Client> clients; 
};
