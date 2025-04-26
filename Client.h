#pragma once
#include "Person.h"
#include <iostream>
#include "Validation.h"
#include <fstream>
class FilesHelper;
using namespace std;

class Client : public Person {
private:
    double balance;

public:
    Client() : balance(0.0) {}

    Client(int id,  string name,  string password, double balance)
        : Person(id, name, password), balance(balance) {
    }

    void setBalance(double balance) {
        this->balance=balance;
    }

    double getBalance()  {
        return balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. Your balance now = " << balance << "$" << endl;
        }
        else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful. Your balance now = " << balance << "$" << endl;
        }
        else {
            cout << "Invalid withdrawal amount or insufficient balance!" << endl;
        }
    }

    void transferTo(double amount, Client& recipient) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            recipient.balance += amount;
            cout << "Transfer successful. Your balance now = " << balance << "$" << endl;
        }
        else {
            cout << "Invalid transfer amount or insufficient balance!" << endl;
        }
    }

    void checkBalance() {
        cout << "Your Balance = " << balance << "$" << endl;
    }

    void displayinfo()  {
        Person::displayinfo();
        cout << "Balance: " << balance << "$" << endl;
    }

    void saveToFile();

    void updateLastClientID();
     
   

};
