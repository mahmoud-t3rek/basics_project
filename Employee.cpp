#include "Employee.h"
#include "FilesHelper.h"
#include "FileManager.h"
void Employee::saveToFile() {
    ofstream file("Employee.txt", ios::app);
    if (file) {
        file << getid() << '&' << getname() << '&' << getpassword() << '&' << salary << endl;
        file.close();

        FilesHelper::saveLast("LastEmployeeID.txt", getid());
    }
    else {
        cout << "Error: Unable to open file for saving!" << endl;
    }
}
void Employee::updateLastEmployeeID() {
    int lastId = FilesHelper::getLast("LastEmployeeID.txt"); 
 

    setid(lastId + 1);
    FilesHelper::saveLast("LastEmployeeID.txt", lastId + 1);
}
void Employee::addClient(Client& client) {
    FileManager::addClient();
}



Client* Employee::searchClient(int id) {
    ifstream file("client.txt");
    if (!file) {
        cout << "Error: Unable to open clients file!" << endl;
        return nullptr;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        int clientId;
        string name, password;
        double balance;
        char delim;

        ss >> clientId >> delim;
        getline(ss, name, '&');
        getline(ss, password, '&');
        ss >> balance;

        if (clientId == id) {
            cout << " Client Found!\n";
            cout << " ID: " << clientId << "\n";
            cout << " Name: " << name << "\n";
            cout << " Balance: " << balance << "\n";
            file.close();
            return new Client(clientId, name, password, balance);
        }
    }

    file.close();
    return nullptr; 
}
void Employee::editClient(int id, string name, string password, double balance) {
    ifstream inFile("Client.txt");
    if (!inFile.is_open()) {
        cout << "Error: Unable to open Clients.txt for reading!" << endl;
        return;
    }

    vector<Client> clients;
    string line;

  
    while (getline(inFile, line)) {
        Client c = Parser::parseToClient(line);
        if (c.getid() == id) {
            
            c.setname(name);
            c.setpassword(password);
            c.setBalance(balance);
        }
        clients.push_back(c);
    }
    inFile.close();

    
    ofstream outFile("Client.txt", ios::trunc);
    if (!outFile.is_open()) {
        cout << "Error: Unable to open Clients.txt for writing!" << endl;
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
void Employee::listClient() {
    FilesHelper::getClients();
}




