#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void DFS(int start, const vector<vector<int>>& adj) {
    vector<bool> visited(adj.size(), false);
    stack<int> s;

    s.push(start);

    while (!s.empty()) {
        int v = s.top();
        s.pop();

        if (!visited[v]) {
            cout << v << " ";
            visited[v] = true;
        }

        for (int u : adj[v]) {
            if (!visited[u]) {
                s.push(u);
            }
        }
    }
}

int main() {
    int n = 6;  // Số lượng đỉnh
    vector<vector<int>> adj(n);

    // Thêm các cạnh vào đồ thị
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[1].push_back(4);
    adj[2].push_back(5);

    // Bắt đầu DFS từ đỉnh 0
    cout << "DFS bat dau tu dinh 0: ";
    DFS(0, adj);

    return 0;
}
