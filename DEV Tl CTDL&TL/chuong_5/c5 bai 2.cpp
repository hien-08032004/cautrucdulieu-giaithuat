#include <iostream>
using namespace std;

// Định nghĩa cấu trúc của một nút trong danh sách móc nối vòng
struct Node {
    int data;
    Node* next;
};

// Hàm chèn một nút mới vào đầu danh sách móc nối vòng
void insertAtHead(Node*& head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;  // Móc nối vòng
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
}

// Hàm chèn một nút mới vào cuối danh sách móc nối vòng
void insertAtTail(Node*& head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;  // Móc nối vòng
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

// Hàm duyệt và in danh sách móc nối vòng
void display(Node* head) {
    if (head == NULL) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

// Hàm xóa nút đầu tiên trong danh sách móc nối vòng
void deleteAtHead(Node*& head) {
    if (head == NULL) return;

    if (head->next == head) {  // Chỉ có một nút trong danh sách
        delete head;
        head = NULL;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        Node* delNode = head;
        head = head->next;
        temp->next = head;
        delete delNode;
    }
}

// Hàm xóa nút cuối cùng trong danh sách móc nối vòng
void deleteAtTail(Node*& head) {
    if (head == NULL) return;

    if (head->next == head) {  // Chỉ có một nút trong danh sách
        delete head;
        head = NULL;
    } else {
        Node* temp = head;
        Node* prev = NULL;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        delete temp;
    }
}

// Hàm xóa nút theo giá trị trong danh sách móc nối vòng
void deleteByValue(Node*& head, int value) {
    if (head == NULL) return;

    // Trường hợp nút đầu tiên chứa giá trị cần xóa
    if (head->data == value) {
        deleteAtHead(head);
        return;
    }

    Node* temp = head;
    Node* prev = NULL;

    // Tìm nút chứa giá trị cần xóa
    do {
        prev = temp;
        temp = temp->next;
    } while (temp != head && temp->data != value);

    // Nếu tìm thấy giá trị cần xóa
    if (temp->data == value) {
        prev->next = temp->next;
        delete temp;
    }
}

// Hàm nhập danh sách từ bàn phím
void inputList(Node*& head, int n) {
    int value;
    cout << "Nhap " << n << " phan tu cho danh sach:\n";
    for (int i = 0; i < n; i++) {
        cout << "Nhap phan tu " << i + 1 << ": ";
        cin >> value;
        insertAtTail(head, value);  // Thêm vào cuối danh sách
    }
}

int main() {
    Node* head = NULL;  // Khởi tạo danh sách rỗng
    int choice, value, n;

    while (true) {
        cout << "\n--- MENU ---\n";
        cout << "1. Nhap danh sach tu ban phim\n";
        cout << "2. Nhap mot phan tu vao cuoi danh sach\n";
        cout << "3. Nhap mot phan tu vao dau danh sach\n";
        cout << "4. Xoa nut dau tien\n";
        cout << "5. Xoa nut cuoi cung\n";
        cout << "6. Xoa nut theo gia tri\n";
        cout << "7. Hien thi danh sach\n";
        cout << "0. Thoat\n";
        cout << "Lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Nhap so luong phan tu trong danh sach: ";
                cin >> n;
                inputList(head, n);  // Gọi hàm nhập danh sách
                cout << "Danh sach sau khi nhap: ";
                display(head);
                break;

            case 2:
                cout << "Nhap gia tri can chen vao cuoi: ";
                cin >> value;
                insertAtTail(head, value);
                cout << "Danh sach sau khi chen: ";
                display(head);
                break;

            case 3:
                cout << "Nhap gia tri can chen vao dau: ";
                cin >> value;
                insertAtHead(head, value);
                cout << "Danh sach sau khi chen: ";
                display(head);
                break;

            case 4:
                deleteAtHead(head);
                cout << "Danh sach sau khi xoa nut dau tien: ";
                display(head);
                break;

            case 5:
                deleteAtTail(head);
                cout << "Danh sach sau khi xoa nut cuoi cung: ";
                display(head);
                break;

            case 6:
                cout << "Nhap gia tri can xoa: ";
                cin >> value;
                deleteByValue(head, value);
                cout << "Danh sach sau khi xoa nut co gia tri " << value << ": ";
                display(head);
                break;

            case 7:
                cout << "Danh sach hien tai: ";
                display(head);
                break;

            case 0:
                cout << "Thoat chuong trinh.\n";
                return 0;

            default:
                cout << "Lua chon khong hop le. Vui long chon lai.\n";
        }
    }

    return 0;
}
