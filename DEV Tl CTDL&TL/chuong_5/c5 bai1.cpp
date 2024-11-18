//Bài 1: Cho danh sách móc nối đơn có nút đầu danh sách 
//trỏ bởi con trỏ P, với trường info trong các nút là các số nguyên dương. 
//Hãy trình bày giải thuật bổ xung phần tử mới vào cuối danh sách. 
#include <iostream>
using namespace std;

// Định nghĩa cấu trúc của một nút trong danh sách liên kết đơn
struct Node {
    int info;       // Dữ liệu của nút (số nguyên dương)
    Node* next;     // Con trỏ tới nút tiếp theo

    // Constructor khởi tạo nút với giá trị info
    Node(int value) : info(value), next(nullptr) {}
};

// Định nghĩa lớp Danh sách liên kết đơn
class SinglyLinkedList {
private:
    Node* head;     // Con trỏ tới nút đầu tiên của danh sách

public:
    // Constructor khởi tạo danh sách rỗng
    SinglyLinkedList() : head(nullptr) {}

    // 1. Thêm một nút vào cuối danh sách
    void insertAtEnd(int data) {
        Node* newNode = new Node(data);  // Tạo nút mới với dữ liệu

        // Nếu danh sách rỗng, gán nút mới là head
        if (!head) {
            head = newNode;
            return;
        }

        // Nếu danh sách không rỗng, duyệt qua danh sách để tìm nút cuối
        Node* temp = head;
        while (temp->next) {  // Duyệt đến nút cuối (nút có next = nullptr)
            temp = temp->next;
        }

        // Thêm nút mới vào cuối danh sách
        temp->next = newNode;
    }

    // 2. Hiển thị tất cả các phần tử trong danh sách
    void display() {
        if (!head) {
            cout << "Danh sach rong!" << endl;
            return;
        }

        Node* temp = head;
        while (temp) {  // Duyệt qua tất cả các nút
            cout << temp->info << " -> ";  // In dữ liệu của mỗi nút
            temp = temp->next;             // Chuyển tới nút tiếp theo
        }
        cout << "NULL" << endl;  // Biểu thị kết thúc danh sách
    }
};

// Chương trình chính
int main() {
    SinglyLinkedList list;  // Khởi tạo danh sách liên kết đơn
    int choice, value, n;

    // Menu chính để người dùng lựa chọn các thao tác
    while (true) {
        cout << "\n--- MENU ---\n";
        cout << "1. Nhap danh sach cac phan tu tu ban phim\n";
        cout << "2. Them phan tu vao cuoi\n";
        cout << "3. Hien thi danh sach\n";
        cout << "0. Thoat\n";
        cout << "Lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Nhap so luong phan tu: ";
                cin >> n;
                cout << "Nhap cac phan tu:\n";
                for (int i = 0; i < n; i++) {
                    cout << "Phan tu " << i + 1 << ": ";
                    cin >> value;
                    list.insertAtEnd(value);  // Thêm phần tử vào cuối danh sách
                }
                break;

            case 2:
                cout << "Nhap gia tri phan tu muon them vao cuoi: ";
                cin >> value;
                list.insertAtEnd(value);  // Thêm phần tử vào cuối danh sách
                cout << "Danh sach sau khi them: ";
                list.display();
                break;

            case 3:
                cout << "Danh sach hien tai: ";
                list.display();
                break;

            case 0:
                cout << "Thoat chuong trinh.\n";
                return 0;

            default:
                cout << "Lua chon khong hop le.\n";
        }

        // Dừng chương trình để người dùng xem kết quả
        cout << "\nNhan phim bat ky de tiep tuc...";
        cin.ignore();
        cin.get();
    }
}
