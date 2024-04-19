#include <iostream>

int main() {
    int localVariable = 10;
    int* ptr = &localVariable; 

    delete ptr; // Lỗi vì đây con trỏ ko được tạo bởi toán tử new 

    return 0;
}
