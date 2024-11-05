#include "Orders.h"

Orders::Orders() : customerID("") {}

Orders::Orders(const string& customerId) : customerID(customerId) {}

void Orders::addInvoice(const Invoice& invoice) {
    invoices.pushback(invoice);
}

string Orders::getCustomerID() const {
    return customerID;
}

void Orders::setCustomerID(const string& id) {
    customerID = id;
}
