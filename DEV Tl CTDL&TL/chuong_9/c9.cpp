#include <iostream>
#include <algorithm>
using namespace std;

// Hàm tìm kiếm nhị phân
int binarySearch(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        // Tính chỉ số giữa
        int mid = low + (high - low) / 2;

        // Kiểm tra nếu phần tử cần tìm là phần tử giữa
        if (arr[mid] == target) {
            return mid;  // Trả về chỉ số của phần tử cần tìm
        }
        // Nếu phần tử cần tìm lớn hơn, bỏ qua nửa mảng bên trái
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        // Nếu phần tử cần tìm nhỏ hơn, bỏ qua nửa mảng bên phải
        else {
            high = mid - 1;
        }
    }
    
    return -1;  // Nếu không tìm thấy, trả về -1
}

int main() {
    int arr[] = {8, 0, 3, 2, 0, 0, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Hiển thị dãy số ban đầu
    cout << "Day so ban dau: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Sắp xếp dãy số
    sort(arr, arr + n);

    // Hiển thị dãy số sau khi sắp xếp
    cout << "Day so sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int target = 3;  // Phần tử cần tìm
    int result = binarySearch(arr, n, target);  // Tìm kiếm nhị phân

    if (result != -1) {
        cout << "Phan tu " << target << " tim thay tai chi so: " << result << endl;
    } else {
        cout << "Phan tu " << target << " khong ton tai trong mang." << endl;
    }

    return 0;
}
