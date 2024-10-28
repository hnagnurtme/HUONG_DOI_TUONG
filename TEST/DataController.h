#pragma once
#include "Product.h"
#include  "Vector.h"
#include <vector>
#include <string>
using namespace std; 

class DataController {
public:
    DataController(const string& filename);
    Vector<Product> loadProductData(); 

private:
    string productFileName;
    Product parseProduct(const string& line);
};

