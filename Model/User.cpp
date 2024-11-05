#include "User.h"
#include <iostream>
#include <stdexcept>

void User::login(const string& email, const string& password) {
    if (this->email == email && this->password == password) {
        cout << "Login successful for user: " << name << endl;
    } else {
        cout << "Login failed. Incorrect email or password." << endl;
    }
}

void User::logout() {
    cout << "User " << name << " has logged out." << endl;
}

void User::displayInfo() const {
    cout << "User ID: " << userId << endl;
    cout << "Name: " << name << endl;
    cout << "Email: " << email << endl;
    cout << "Phone: " << phone << endl;
}

void User::recoverPassword() {
    cout << "Recovering password for user: " << name << endl;
}
