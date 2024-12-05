//
// Created by Quannn on 12/4/2024.
//
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9 + 7;
int arr[N];
int segTree[4*N];
int n;

int getMaxFromNode(int id, int l, int r, int i, int j) {
    if (l > j || r < i) return INF;
    if (i <= l || j >= r) return segTree[id];
    int mid = (l+r)/2;
    int maxLeft = getMaxFromNode(2 * id, l, mid, i, j);
    int maxRight = getMaxFromNode(2 * id+1, mid+1, r, i, j);
    return max(maxLeft, maxRight);
}

int getMax(int i, int j) {
    return getMaxFromNode(1, 1, n, i, j);
}

void updateFromNode(int id, int l, int r, int idx, int val) {
    if (l > r) return;
    if (idx < l || idx > r) return;
    if (l == r) {
        segTree[id] = val;
        return;
    }
    int mid = (l+r)/2;
    updateFromNode(2 * id, l, mid, idx, val);
    updateFromNode(2 * id + 1, mid + 1, r, idx, val);
    segTree[id] = max(segTree[2*id],segTree[2*id+1]);
}

void update(int idx, int val) {
    updateFromNode(1, 1, n, idx, val);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> arr[i];
    }
    int m;
    cin >> m;
    string text;
    int u, v;
    while (m--) {
        cin >> text;
        if (text == "get-max") {
            cin >> u >> v;
            cout << getMax(u, v) << endl;
        }
        else if (text == "update") {
            cin >> u >> v;
            update(u, v);
        }
    }
    return 0;
}
