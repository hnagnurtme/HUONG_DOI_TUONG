#pragma once
#include <string>
#include "Vector.h"
#include "Pair.h"
#include "Product.h"
#include "Cart.h"

using namespace std;

class Invoice {
private:
    string invoiceId;
    string customerId;
    Vector<Pair<Product, int>> products;
    string invoiceDate;
    double totalAmount;
    string deliveryDate;
    string paymentMethod;

public:
    Invoice();
    Invoice(const Cart& cart);
    Invoice(const string& invoiceId, const string& customerId, const Vector<Pair<Product, int>>& products, double totalAmount);
    
    string displayInvoice() const;
    
    string getInvoiceId() const;
    void setInvoiceId(const string& id);
    
    string getCustomerId() const;
    void setCustomerId(const string& id);
    
    void setInvoiceDate();
    string getInvoiceDate() const;

    void setTotalAmount(double amount);
    double getTotalAmount() const;

    Vector<Pair<Product, int>> getProducts() const;

    void setDeliveryDate(const string& deliveryDate);
    void setPaymentMethod(const string& paymentMethod);
};
