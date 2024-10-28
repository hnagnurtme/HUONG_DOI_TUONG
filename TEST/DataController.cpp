#include "DataController.h"
#include "Vector.h"
#include "Product.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

DataController::DataController(const string& filename) : productFileName(filename) {}

Vector<Product> DataController::loadProductData() {
    Vector<Product> products;
    ifstream file(productFileName);

    std::cout << "Trying to open file: " << productFileName << std::endl; 

    if (!file.is_open()) {
        throw runtime_error("Không thể mở file: " + productFileName);
    }

    string line;
    while (getline(file, line)) {
        Product product = parseProduct(line);
        products.pushback(product); 
    }

    file.close();
    return products;
}

Product DataController::parseProduct(const string& line) {
    istringstream ss(line);
    string id, name, category, priceStr, stockStr, description, sizesStr, colorsStr, brand;

    getline(ss, id, ';');         
    getline(ss, name, ';');
    getline(ss, category, ';');
    getline(ss, priceStr, ';');
    getline(ss, stockStr, ';');
    getline(ss, description, ';');
    getline(ss, sizesStr, ';');
    getline(ss, colorsStr, ';');
    getline(ss, brand, ';');

    double price = stod(priceStr);
    int stock = stoi(stockStr);

    
    Vector<Pair<int, int>> sizes;
    istringstream sizesStream(sizesStr);
    string sizePair;

    
    while (getline(sizesStream, sizePair, '}')) {
        if (sizePair.empty()) continue;

        
        if (sizePair.front() == '{') {
            sizePair.erase(sizePair.begin());
        }

        
        istringstream sizeStream(sizePair);
        int size, countOfSize;
        char delimiter;

        if (sizeStream >> size >> delimiter >> countOfSize) {
            sizes.pushback(Pair<int, int>{size, countOfSize}); 
        }
    }


    Vector<string> colors;
    istringstream colorsStream(colorsStr);
    string color;

    while (getline(colorsStream, color, ',')) {
        color.erase(remove(color.begin(), color.end(), '{'), color.end());
        color.erase(remove(color.begin(), color.end(), '}'), color.end());
        
        if (!color.empty()) {
            colors.pushback(color); 
        }
    }

    return Product(id, name, category, price, stock, description, sizes, colors, brand);
}

