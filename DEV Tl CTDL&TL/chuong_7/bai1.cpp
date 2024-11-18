#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Cấu trúc lưu cạnh của đồ thị
struct Edge {
    int u, v; // Hai đỉnh của cạnh
    int weight; // Trọng số của cạnh
};

// Hàm so sánh để sắp xếp cạnh theo trọng số tăng dần
bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Tìm đại diện (root) của một đỉnh trong cây (sử dụng Union-Find)
int findRoot(int u, vector<int>& parent) {
    if (u != parent[u]) {
        parent[u] = findRoot(parent[u], parent); // Đường đi nén
    }
    return parent[u];
}

// Hợp nhất hai tập hợp (Union)
void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
    int rootU = findRoot(u, parent);
    int rootV = findRoot(v, parent);

    if (rootU != rootV) {
        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

// Thuật toán Kruskal để tìm cây khung tối thiểu
void kruskalMST(int V, vector<Edge>& edges) {
    // Sắp xếp các cạnh theo trọng số tăng dần
    sort(edges.begin(), edges.end(), compare);

    vector<int> parent(V + 1), rank(V + 1, 0); // Mảng parent và rank
    for (int i = 1; i <= V; i++) {
        parent[i] = i; // Mỗi đỉnh ban đầu là root của chính nó
    }

    vector<Edge> mst; // Lưu các cạnh của cây khung tối thiểu
    int totalWeight = 0;

    for (Edge edge : edges) {
        if (findRoot(edge.u, parent) != findRoot(edge.v, parent)) {
            // Nếu cạnh không tạo chu trình, thêm nó vào cây khung
            mst.push_back(edge);
            totalWeight += edge.weight;
            unionSet(edge.u, edge.v, parent, rank); // Hợp nhất tập hợp
        }
    }

    // In kết quả
    cout << "Cac canh trong cay khung toi thieu (MST):\n";
    for (Edge edge : mst) {
        cout << "(" << edge.u << ", " << edge.v << ") - Trong so: " << edge.weight << endl;
    }
    cout << "Tong trong so cua cay khung toi thieu: " << totalWeight << endl;
}

int main() {
    int V = 5; // Số đỉnh
    vector<Edge> edges = {
        {1, 2, 12}, {1, 5, 9}, {1, 4, 7},
        {2, 4, 17}, {2, 3, 20}, {3, 4, 25},
        {4, 5, 40}
    };

    kruskalMST(V, edges);

    return 0;
}
