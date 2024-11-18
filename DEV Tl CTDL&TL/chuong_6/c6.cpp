#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(NULL), right(NULL) {}
};

// Hàm để chèn nút vào cây nhị phân theo mức (level order)
Node* insertLevelOrder(int arr[], Node* root, int i, int n) {
    if (i < n) {
        Node* temp = new Node(arr[i]);
        root = temp;
        root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);
        root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
    }
    return root;
}

// Hàm duyệt cây theo thứ tự trước (Pre-order)
void preOrder(Node* node) {
    if (node == NULL)
        return;
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

// Hàm duyệt cây theo thứ tự giữa (In-order)
void inOrder(Node* node) {
    if (node == NULL)
        return;
    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
}

// Hàm duyệt cây theo thứ tự sau (Post-order)
void postOrder(Node* node) {
    if (node == NULL)
        return;
    postOrder(node->left);
    postOrder(node->right);
    cout << node->data << " ";
}

int main() {
    int arr[] = {8, 0, 3, 0, 2, 0, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    Node* root = insertLevelOrder(arr, root, 0, n);

    cout << "Duyet theo thu tu truoc (Pre-order): ";
    preOrder(root);
    cout << endl;

    cout << "Duyet theo thu tu giua (In-order): ";
    inOrder(root);
    cout << endl;

    cout << "Duyet theo thu tu sau (Post-order): ";
    postOrder(root);
    cout << endl;

    return 0;
}
