#include "Admin.h"
#include "FilesHelper.h"
#include "FileManager.h"

void Admin::saveToFile() {
    ofstream file("Admin.txt", ios::app);
    if (file) {
        file << getid() << '&' << getname() << '&' << getpassword() << '&' << salary << endl;
        file.close();

        FilesHelper::saveLast("LastAdminID.txt", getid());
    }
    else {
        cout << "Error: Unable to open file for saving!" << endl;
    }
}
void Admin::updateLastAdminID() {
    int lastId = FilesHelper::getLast("LastAdminID.txt");
    if (lastId == -1) lastId = 0; 

    setid(lastId + 1);
}
void Admin::addEmployee(Employee& employee) {
    FileManager::addEmployee();
}

Employee* Admin::searchEmployee(int id) {
    ifstream file("Employee.txt");
    if (!file) {
        cout << "Error: Unable to open clients file!" << endl;
        return nullptr;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        int employeeId;
        string name, password;
        double salary;
        char delim;

        ss >> employeeId >> delim;
        getline(ss, name, '&');
        getline(ss, password, '&');
        ss >> salary;

        if (employeeId == id) {
            cout << " Employee Found!\n";
            cout << " ID: " << employeeId << "\n";
            cout << " Name: " << name << "\n";
            cout << " Balance: " << salary << "\n";
            cout << " Password: " << password << endl;
            file.close();
            return new Employee(employeeId, name, password, salary);
        }
    }

    file.close();
    return nullptr;
}
void Admin::listEmployee() {
    FilesHelper::getEmployees();
}
void Admin::editEmployee(int id, string name, string password, double salary) {

ifstream inFile("Employee.txt");
if (!inFile.is_open()) {
    cout << "Error: Unable to open Clients.txt for reading!" << endl;
    return;
}

vector<Employee> employee;
string line;


while (getline(inFile, line)) {
    Employee c = Parser::parseToEmployee(line);
    if (c.getid() == id) {

        c.setname(name);
        c.setpassword(password);
        c.setSalary(salary);
    }
    employee.push_back(c);
}
inFile.close();


ofstream outFile("Client.txt", ios::trunc);
if (!outFile.is_open()) {
    cout << "Error: Unable to open Clients.txt for writing!" << endl;
    return;
}

for (size_t i = 0; i < employee.size(); i++) {
    outFile << employee[i].getid() << '&'
        << employee[i].getname() << '&'
        << employee[i].getpassword() << '&'
        << employee[i].getSalary() << endl;
}

outFile.close();
cout << "Employee updated successfully!" << endl;
}
