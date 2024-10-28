#include "DataController.h"
#include "Product.h"
#include <iostream>

int main() {
    try {
        // Khởi tạo DataController với tên file sản phẩm
        DataController dataController("D:/HUONG_DOI_TUONG/Data/ProductInformation.csv");

        // Tải dữ liệu sản phẩm từ file
        Vector<Product> products = dataController.loadProductData();

        // In thông tin của các sản phẩm
        for (long i = 0; i < products.getSize(); ++i) {
            Product product = products[i];
            std::cout << "ID: " << product.getProductId() << std::endl; // Sửa từ getId() thành getProductId()
            std::cout << "Name: " << product.getName() << std::endl;
            std::cout << "Category: " << product.getCategory() << std::endl;
            std::cout << "Price: " << product.getPrice() << std::endl;
            std::cout << "Stock: " << product.getStock() << std::endl;
            std::cout << "Description: " << product.getDescription() << std::endl;

            // In kích thước
            std::cout << "Sizes: ";
            Vector<Pair<int, int>> sizes = product.getSizes(); // Lưu kích thước vào biến
            for (long j = 0; j < sizes.getSize(); ++j) {
                std::cout << "(" << sizes[j].getFirst() << ", " << sizes[j].getSecond() << ") "; // Sửa để gọi phương thức getFirst() và getSecond()
            }
            std::cout << std::endl;

            // In màu sắc
            std::cout << "Colors: ";
            Vector<string> colors = product.getColors(); // Lưu màu sắc vào biến
            for (long j = 0; j < colors.getSize(); ++j) {
                std::cout << colors[j] << " "; // Sửa để sử dụng biến colors
            }
            std::cout << std::endl;

            std::cout << "Brand: " << product.getBrand() << std::endl;
            std::cout << "---------------------------------" << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
