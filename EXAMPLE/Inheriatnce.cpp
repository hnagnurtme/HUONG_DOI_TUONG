#include <iostream>
#include <vector>
#include <list>

// Định nghĩa lớp template với một tham số kiểu và một tham số template
template <typename T, template <typename, typename> class Container = std::vector>
class MyContainer {
public:
    // Thêm giá trị vào container
    void addValue(T value) {
        data.push_back(value);
    }

    // In tất cả các giá trị trong container
    void printValues() const {
        for (const auto& value : data) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

private:
    Container<T, std::allocator<T>> data; // Sử dụng template container để lưu trữ dữ liệu
};

int main() {
    // Tạo đối tượng MyContainer cho kiểu int sử dụng std::vector
    MyContainer<int> intVectorContainer;
    intVectorContainer.addValue(1);
    intVectorContainer.addValue(2);
    intVectorContainer.addValue(3);
    std::cout << "Int Vector Container: ";
    intVectorContainer.printValues();

    // Tạo đối tượng MyContainer cho kiểu double sử dụng std::list
    MyContainer<double, std::list> doubleListContainer;
    doubleListContainer.addValue(1.1);
    doubleListContainer.addValue(2.2);
    doubleListContainer.addValue(3.3);
    std::cout << "Double List Container: ";
    doubleListContainer.printValues();

    return 0;
}