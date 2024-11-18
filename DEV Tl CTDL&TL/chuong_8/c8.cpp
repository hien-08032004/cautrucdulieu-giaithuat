#include <iostream>
using namespace std;

// Ham sap xep Selection Sort
void selectionSort(int arr[], int n) {
    // Duyet qua tat ca cac phan tu trong mang
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;  // Gia su phan tu nho nhat la phan tu o vi tri i
        
        // Tim phan tu nho nhat trong day tu i+1 den n-1
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;  // Cap nhat chi so phan tu nho nhat
            }
        }
        
        // Neu phan tu nho nhat khong phai la phan tu o vi tri i, hoan doi chung
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }

        // In ra day sau moi buoc duyet
        cout << "Buoc " << i + 1 << ": ";
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

// Ham in day so
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {0, 8, 0, 3, 2, 0, 0, 4};  // Day so ban dau
    int n = sizeof(arr) / sizeof(arr[0]);  // Tinh so phan tu trong day

    cout << "Day so ban dau: ";
    printArray(arr, n);
    cout << endl;

    selectionSort(arr, n);  // Thuc hien sap xep Selection Sort

    cout << "Day sau khi sap xep: ";
    printArray(arr, n);  // In ra day so sau khi sap xep

    return 0;
}
