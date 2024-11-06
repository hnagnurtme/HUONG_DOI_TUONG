#include "Product.h"
#include "Cart.h"
#include <iostream>
using namespace std;

int main() {
    // Create a Cart instance
    Cart cart;

    // Create Product instances
    Product apple("001", "Apple", "Fruits", 0.99, 100, "Fresh red apple", {"Sweet", "Crispy"}, "BrandA");
    Product banana("002", "Banana", "Fruits", 0.59, 150, "Ripe yellow banana ", {"Sweet", "Soft"}, "BrandB");

    // Add products to the cart
    cart.addItem(&apple,1);

    cart.addItem(&banana,1);
    // Display product information
    cout << "Product Information:\n";
    apple.displayInfo();
    banana.displayInfo();

    // Show products in the cart
    cout << "\nProducts in Cart:\n";
    cart.displayCartItems();

    return 0;
}