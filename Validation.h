#pragma once
#include <iostream>
#include <string>
using namespace std;


class Validation {
private:
	static bool valid_name(string name) {
		if (name.size() < 5 || name.size() > 20)
			return false;
		for (int i = 0; i < name.size(); i++) {
			if (!isalpha(name[i]))
				return false;
		}
		return true;
	}
	static bool valid_Password(string password) {
		if (password.size() < 8 || password.size() > 20) {
			return false;
		}
		return true;
	}
public:

	static string entername() {
		string name;
		cout << "enter your name: ";
		cin >> name;
		while (!valid_name(name)) {
			cout << "Name must be 5 to 20 alphapitic char" << endl;
			cout << "enter your name" << endl;
			cin >> name;
		}
		return name;
	}
	static string enterPassword() {
		string Password;
		cout << "enter your password: ";
		cin >> Password;
		while (!valid_Password(Password)) {
			cout << "Password must be 8 to 20  characters" << endl;
			cout << "enter your passwarod" << endl;
			cin >> Password;
		}
		return Password;
	}
	static double valid_balance() {
		double balance;
		cout << "enter your balance: ";
		cin >> balance;
		while (balance < 1500) {
			cout << "Balance must be at least 1500" << endl;
			cout << "enter your balance: " ;
			cin >> balance;
		}
		return balance;
	}

	static double valid_salary() {
		double salary;
		cout << "enter your salary: ";
		cin >> salary;
		while (salary < 5000) {
			cout << "Salary must be at least 5000" << endl;
			cout << "enter your salary: ";
			cin >> salary;
		}
		return salary;
	}
};

