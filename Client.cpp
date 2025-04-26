#include "Client.h"
#include "FilesHelper.h"

void Client::saveToFile() {
    ofstream file("Clients.txt", ios::app);
    if (file) {
        file << getid() << '&' << getname() << '&' << getpassword() << '&' << balance << endl;
        file.close();
        FilesHelper::saveLast("LastClientID.txt", getid());
    }
    else {
        cout << "Error: Unable to open file for saving!" << endl;
    }
}

void Client::updateLastClientID() {
    int lastId = FilesHelper::getLast("LastClientID.txt"); 
    if (lastId == -1) lastId = 0; 
    setid(lastId + 1); 
    FilesHelper::saveLast("LastClientID.txt", lastId + 1);
}
