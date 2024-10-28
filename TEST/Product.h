#pragma once
#include <string>
using namespace std;
#include "Vector.h"
#include "Pair.h"

class Product {
private:
    string productId;
    string name;
    string category;
    double price;
    int stock;
    string description;
    Vector<Pair<int,int>> sizes;
    Vector<string> colors;
    string brand;

public:
    Product(string id, const string& name, const string& category, double price, int stock,
            const string& description, const Vector<Pair<int, int>>& sizes,
            const Vector<string>& colors, const string& brand);
    string getProductId() const;
    string getName() const;
    string getCategory() const;
    double getPrice() const;
    int getStock() const;
    string getDescription() const;
    Vector<Pair<int, int>> getSizes() const;
    Vector<string> getColors() const;
    string getBrand() const;
    void setName(const string& newName);
    void setPrice(double newPrice);
    void setStock(int newStock);
    void setDescription(const string& newDescription);
    void displayInfo() const;
    bool isAvailable(int requestedQuantity) const;
};
