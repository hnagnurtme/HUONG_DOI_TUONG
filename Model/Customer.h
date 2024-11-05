#pragma once
#include "User.h"
#include "Cart.h"
#include "Orders.h"
#include "Vector.h"
#include <string>
using namespace std;
class Customer : public User {
private:
    Cart cart;
    Vector<Orders> orderHistory;

public:
    void viewCart() const;
    void addToCart(const Product& product, int quantity);
    void placeOrder();
    void viewOrderHistory() const;
};
