#pragma once
#include "User.h"
#include "Product.h"
#include "Vector.h"
#include "Pair.h"
#include <string>
#include <iostream>

using namespace std;
class Product;
class Cart {
private:
    Vector<Pair<Product*, int>> items;
    string customerID;
public:
    Cart(string id ="");
    void setCartID(string id);
    void addItem(Product* product, int quantity);
    void removeItem(string productId);
    void clearCart();
    void displayCartItems() const;
    Vector<Pair<Product*, int>> getItems() const;
    string getCustomerID() const;
    bool contains(const string& productId) const;
    void reduceItem(const string& productId, int quantity);
    int getItemQuantity(const string& productId) const;
    bool isEmptyCart();
};
