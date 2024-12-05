#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<pair<int, int>> adj[N];
int n, d[N], w[N][N];

void input() {
    cin >> n;
    int u, v, w;
    for (int i = 1;i <= n;i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
}

void dfs(int u) {
    for (const auto &e: adj[u]) {
        int v = e.first, w = e.second;
        if (d[v] == -1) {
            d[v] = d[u] + w;
            dfs(v);
        }
    }
}

int LongestPath() {
    memset(d, -1, sizeof(d));
    dfs(1);
    int x = 1, maxDist = 0;
    for (int u = 1; u <= n;u++) {
        if (d[u] > maxDist) {
            maxDist = d[u];
            x = u;
        }
    }
    memset(d, -1, sizeof(d));
    dfs(x);
    int y = x;
    maxDist = 0;
    for (int u = 1;u <= n;u++) {
        if (d[u] > maxDist) {
            maxDist = d[u];
            y = u;
        }
    }
    return maxDist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    cout << LongestPath() + 1 << endl;
    return 0;
}

