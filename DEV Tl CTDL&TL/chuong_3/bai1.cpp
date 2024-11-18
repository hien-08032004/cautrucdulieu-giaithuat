#include <iostream>
using namespace std;

// Hàm đệ quy tính giai thừa
int factorial(int n) {
    // Trường hợp cơ sở
    if (n == 0) {
        cout << "Giai thua cua 0 la: 1" << endl;
        return 1;
    }
    
    // In ra bước tính toán hiện tại
    cout << "Tinh " << n << "! = " << n << " * " << (n - 1) << "!" << endl;
    
    // Đệ quy: n! = n * (n-1)!
    return n * factorial(n - 1);
}

int main() {
    int n;
    cout << "Nhap so n: ";
    cin >> n;
    
    // Tính và hiển thị giai thừa của n
    int result = factorial(n);
    cout << "Giai thua cua " << n << " la: " << result << endl;
    return 0;
}
