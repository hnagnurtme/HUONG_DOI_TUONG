#include "Invoice.h"
#include "Cart.h"
#include <ctime>
#include <iomanip>
#include <sstream>

Invoice::Invoice() : customerId(""), totalAmount(0.0) {
    setInvoiceDate();
    invoiceId = "INV_" + getInvoiceDate();
}

Invoice::Invoice(const Cart& cart) : customerId(cart.getCustomerID()), totalAmount(0.0) {
    products = cart.getItems();
    for (int i = 0; i < products.getSize(); ++i) {
        totalAmount += products[i].getFirst().getPrice() * products[i].getSecond();
    }
    setInvoiceDate();
    invoiceId = "INV_" + getInvoiceDate();
}

Invoice::Invoice(const string& invoiceId, const string& customerId, const Vector<Pair<Product, int>>& products, double totalAmount)
    : invoiceId(invoiceId), customerId(customerId), products(products), totalAmount(totalAmount) {
    setInvoiceDate();
}

string Invoice::displayInvoice() const {
    stringstream ss;
    ss << "Invoice ID: " << invoiceId << "\n";
    ss << "Customer ID: " << customerId << "\n";
    ss << "Invoice Date: " << invoiceDate << "\n";
    ss << "Delivery Date: " << deliveryDate << "\n";  
    ss << "Payment Method: " << paymentMethod << "\n"; 
    ss << "Total Amount: $" << totalAmount << "\n";
    ss << "Products:\n";
    for (int i = 0; i < products.getSize(); ++i) {
        ss << "- Product Name: " << products[i].getFirst().getName() 
           << ", Quantity: " << products[i].getSecond() << "\n";
    }
    return ss.str();
}
Vector<Pair<Product, int>> Invoice:: getProducts() const{
    return products;
}

string Invoice::getInvoiceId() const {
    return invoiceId;
}

void Invoice::setInvoiceId(const string& id) {
    invoiceId = id;
}

string Invoice::getCustomerId() const {
    return customerId;
}

void Invoice::setCustomerId(const string& id) {
    customerId = id;
}

void Invoice::setInvoiceDate() {
    time_t now = time(0);
    tm* localTime = localtime(&now);
    stringstream ss;
    ss << put_time(localTime, "%Y-%m-%d"); 
    invoiceDate = ss.str();
}

string Invoice::getInvoiceDate() const {
    return invoiceDate;
}

void Invoice::setTotalAmount(double amount) {
    totalAmount = amount;
}

double Invoice::getTotalAmount() const {
    return totalAmount;
}

void Invoice::setDeliveryDate(const string& deliveryDate) {
    this->deliveryDate = deliveryDate;
}

void Invoice::setPaymentMethod(const string& paymentMethod) {
    this->paymentMethod = paymentMethod;
}
