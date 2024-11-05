#pragma once
#include "User.h"
#include "Product.h"
#include "Orders.h"
#include "Vector.h"
#include <string>
using namespace std;
class Manager : public User {
public:
    void addProduct(Vector<Product>& products, const Product& product);
    void updateProductStock(Vector<Product>& products, string productId, int newStock);
    void viewOrders(const Vector<Orders>& orders) const;
};
