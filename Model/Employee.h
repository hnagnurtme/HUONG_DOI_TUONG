#pragma once
#include "User.h"
#include "Orders.h"
#include <string>
using namespace std;
class Employee : public User {
private:
    string position;
public:
    void createInvoice(const Orders& order);
};
