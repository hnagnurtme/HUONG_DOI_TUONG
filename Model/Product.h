#pragma once
#include <string>
using namespace std;
#include "User.h"
#include "Vector.h"
#include "Pair.h"
#include "Cart.h"
#include "Invoice.h"

class Cart; 
class Invoice;
class Product;
class Product {
private:
    string productId;
    string name;
    string category;
    double price;
    int stock;
    string imageDescription;
    Vector<string> description;
    string brand;

    Vector<Cart*> cart;
    void addCart(Cart* cart,int quanity);
    Vector<Invoice*> invoice;
    void addInvoice(Invoice* invoice, int count);
public:
    Product();
    Product(string id, const string& name, const string& category, double price, int stock,
            const string& imageDescription,const Vector<string>& description, const string& brand);
    string getProductId() const;
    string getName() const;
    string getCategory() const;
    double getPrice() const;
    int getStock() const;
    string getImageDescription() const;
    Vector<string> getDescription() const;
    string getBrand() const;
    void setProductId(const string& newID);
    void setName(const string& newName);
    void setPrice(double newPrice);
    void setStock(int newStock);
    void setImageDescription(const string& newDescription);
    void displayInfo() const;
    bool isAvailable(int requestedQuantity) const;
    friend class Cart;
    friend class Invoice;
};
