#pragma once
#include <string>
using namespace std;
class User {
protected:
    int userId;
    string name;
    string email;
    string phone;
    string password;

public:
    void login(const string& email, const string& password);
    void logout();
    void displayInfo() const;
    void recoverPassword();
};
