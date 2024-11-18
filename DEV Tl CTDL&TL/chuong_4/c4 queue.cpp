#include <iostream>
using namespace std;

#define MAX 32  // Kích thước tối đa của Queue

class Queue {
private:
    int queue[MAX];  // Mảng lưu trữ phần tử của Queue
    int front, rear; // Chỉ số của phần tử đầu và cuối

public:
    Queue() {
        front = -1;  // Khởi tạo front là -1 (Queue rỗng)
        rear = -1;   // Khởi tạo rear là -1 (Queue rỗng)
    }

    // Kiểm tra xem Queue có đầy không
    bool isFull() {
        return rear == MAX - 1;  // Nếu rear = MAX - 1, Queue đã đầy
    }

    // Kiểm tra xem Queue có rỗng không
    bool isEmpty() {
        return front == -1 || front > rear;  // Nếu front > rear hoặc front = -1, Queue rỗng
    }

    // Hàm enqueue để thêm phần tử vào Queue
    bool enqueue(int data) {
        if (isFull()) {
            cout << "Queue da day, khong the them du lieu!" << endl;
            return false;  // Nếu Queue đầy, không thể thêm phần tử
        }

        // Nếu Queue rỗng, cập nhật front
        if (front == -1) {
            front = 0;
        }

        rear = rear + 1;     // Tăng chỉ số rear
        queue[rear] = data;  // Thêm phần tử vào vị trí rear
        cout << "Da them du lieu: " << data << endl;
        return true;
    }

    // Hàm dequeue để lấy phần tử ra khỏi Queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue rong, khong the lay du lieu!" << endl;
            return -1;  // Trả về -1 nếu Queue rỗng
        }

        int data = queue[front];  // Lấy phần tử đầu tiên
        front = front + 1;        // Di chuyển front đến vị trí tiếp theo
        return data;
    }

    // Hàm hiển thị nội dung của Queue
    void display() {
        if (isEmpty()) {
            cout << "Queue rong!" << endl;
            return;
        }

        cout << "Noi dung cua Queue: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int n, data;

    // Nhập số lượng phần tử muốn đưa vào Queue
    cout << "Nhap so luong phan tu muon chen vao Queue: ";
    cin >> n;

    // Nhập các phần tử từ bàn phím và thêm vào Queue
    for (int i = 0; i < n; i++) {
        cout << "Nhap phan tu thu " << i + 1 << ": ";
        cin >> data;
        q.enqueue(data);  // Thêm phần tử vào Queue
    }

    // Hiển thị nội dung Queue sau khi thêm các phần tử
    q.display();

    // Thực hiện thao tác dequeue
    int dequeuedData = q.dequeue();  // Lấy phần tử ra khỏi Queue
    if (dequeuedData != -1) {
        cout << "Da lay du lieu: " << dequeuedData << endl;
    }

    // Hiển thị lại Queue sau khi dequeue
    q.display();

    return 0;
}
