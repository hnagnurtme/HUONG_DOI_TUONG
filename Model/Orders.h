#pragma once
#include <string>
#include "Vector.h"
#include "Invoice.h"

using namespace std;

class Orders {
private:
    string customerID;
    Vector<Invoice> invoices;

public:
    Orders();
    Orders(const string& customerId);
    void addInvoice(const Invoice& invoice);
    string getCustomerID() const;
    void setCustomerID(const string& id);
};
