#include "Product.h"
#include <iostream>
Product::Product() 
    : productId(""), name(""), category(""), price(0.0), stock(0), imageDescription(""), description(), brand("") {}

Product::Product(string id, const string& name, const string& category, double price, int stock,
                const string& imageDescription, const Vector<string>& description, const string& brand)
    : productId(id), name(name), category(category), price(price), stock(stock),
    imageDescription(imageDescription), description(description), brand(brand) {}

string Product::getProductId() const {
    return productId;
}

string Product::getName() const {
    return name;
}

string Product::getCategory() const {
    return category;
}

double Product::getPrice() const {
    return price;
}

int Product::getStock() const {
    return stock;
}

string Product::getImageDescription() const {
    return imageDescription;
}

Vector<string> Product::getDescription() const {
    return description;
}

string Product::getBrand() const {
    return brand;
}
void Product::setProductId(const string& newID){
    productId = newID;
}
void Product::setName(const string& newName) {
    name = newName;
}

void Product::setPrice(double newPrice) {
    price = newPrice;
}

void Product::setStock(int newStock) {
    stock = newStock;
}

void Product::setImageDescription(const string& newimageDescription) {
    imageDescription = newimageDescription;
}

void Product::displayInfo() const {
    cout << "Product ID: " << productId << endl;
    cout << "Name: " << name << endl;
    cout << "Category: " << category << endl;
    cout << "Price: $" << price << endl;
    cout << "Stock: " << stock << endl;
    cout << "ImageDescription: " << imageDescription << endl;
    cout << endl;
    cout << "Description: ";
    for (long i = 0; i < description.getSize(); ++i) {
        cout << description[i] << " ";
    }
    cout << endl;
    cout << "Brand: " << brand << endl;
}

bool Product::isAvailable(int requestedQuantity) const {
    return requestedQuantity <= stock;
}

void  Product::addCart(Cart* cart, int quanity){
    this->cart.pushback(cart);
    cart->addItem(this,quanity);
}

void Product::addInvoice(Invoice* invoice, int count){
    this->invoice.pushback(invoice);
    invoice->addProduct(this, count);
}