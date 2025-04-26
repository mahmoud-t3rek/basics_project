#pragma once
#include <iostream>
#include "Validation.h"
using namespace std;

class Person {
protected:
    int id;
    string name, password;

public:
    Person() : id(1), name(" "), password(" ") {}
    Person(int id, string name, string password) {
        this->id = id;
        this->name = name;
        this->password = password;
    }
    virtual string toString() const {
        return to_string(id) + "&" + name + "&" + password;
    }

    void setid(int id) { this->id = id; }
    void setname(string name) { this->name = name; }
    void setpassword(string password) { this->password = password; }

    int getid() { return id; }
    string getname() { return name; }
    string getpassword()  { return password; }

    virtual void displayinfo()  {
        cout << "Id: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Password: " << password << endl;
    }
};
