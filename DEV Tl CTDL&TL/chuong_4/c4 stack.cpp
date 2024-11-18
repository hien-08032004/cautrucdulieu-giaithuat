#include <iostream>
using namespace std;

#define MAX 32  // Kích thước tối đa của Stack (32 bits cho số nguyên)

class Stack {
private:
    int stack[MAX];  // Mảng lưu trữ phần tử
    int top;         // Chỉ số của phần tử trên cùng

public:
    Stack() { top = -1; }  // Khởi tạo Stack rỗng

    // Kiểm tra xem Stack có đầy hay không
    bool isFull() {
        return top == MAX - 1;  // Nếu top = MAX - 1, Stack đã đầy
    }

    // Kiểm tra xem Stack có rỗng hay không
    bool isEmpty() {
        return top == -1;  // Nếu top = -1, Stack là rỗng
    }

    // Hàm push để thêm phần tử vào Stack
    void push(int data) {
        if (!isFull()) {
            top = top + 1;      // Tăng top để trỏ đến vị trí tiếp theo
            stack[top] = data;  // Thêm phần tử vào vị trí top
        } else {
            cout << "Khong the chen them du lieu vi Stack da day." << endl;
        }
    }

    // Hàm pop để lấy phần tử ra khỏi Stack
    int pop() {
        if (!isEmpty()) {
            int data = stack[top];  // Lấy phần tử trên cùng
            top = top - 1;          // Giảm top để loại bỏ phần tử đó
            return data;
        } else {
            cout << "Khong the lay du lieu, Stack la trong." << endl;
            return -1;  // Trả về giá trị không hợp lệ khi Stack rỗng
        }
    }

    // Hàm in nội dung của Stack
    void display() {
        if (isEmpty()) {
            cout << "Stack rong!" << endl;
        } else {
            cout << "Noi dung cua Stack: ";
            for (int i = 0; i <= top; i++) {
                cout << stack[i] << " ";
            }
            cout << endl;
        }
    }

    // Hàm chuyển đổi số thập phân sang nhị phân và lưu vào Stack
    void convertToBinary(int num) {
        while (num > 0) {
            push(num % 2);  // Thêm phần dư vào Stack
            num = num / 2;  // Chia số cho 2
        }
    }
};

int main() {
    Stack s;
    int num = 8032004;  // Số nguyên cần chuyển đổi

    // Chuyển đổi số thập phân sang nhị phân và lưu vào Stack
    cout << "Chuyen doi so " << num << " sang nhi phan:" << endl;
    s.convertToBinary(num);

    // Hiển thị nội dung Stack (từng phần tử trong Stack)
    cout << "Phan tu trong Stack (tu tren xuong duoi):" << endl;
    s.display();

    // In ra số nhị phân từ Stack
    cout << "So nhi phan cua " << num << " la: ";
    while (!s.isEmpty()) {
        cout << s.pop();  // Lấy từng phần tử và in ra
    }
    cout << endl;

    return 0;
}
