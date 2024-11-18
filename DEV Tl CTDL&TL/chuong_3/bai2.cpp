#include <iostream>
using namespace std;

// Thủ tục đệ quy tính F(n)
int F(int n) {
    // Trường hợp cơ sở: F(n) = 1 nếu n <= 4
    if (n <= 4) {
        return 1;
    }
    // Trường hợp đệ quy: F(n) = F(n-1) + F(n-4) nếu n > 4
    return F(n - 1) + F(n - 4);
}

int main() {
    int n;
    cout << "Nhap n (0 < n <= 20): ";
    cin >> n;

    // Kiểm tra điều kiện nhập liệu
    if (n <= 0 || n > 20) {
        cout << "Gia tri n khong hop le!" << endl;
    } else {
        // Tính và hiển thị F(n)
        cout << "F(" << n << ") = " << F(n) << endl;
    }

    return 0;
}
