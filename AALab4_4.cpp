//
// Created by Quannn on 12/4/2024.
//
#include <bits/stdc++.h>
using namespace std;

typedef pair <int,int> ii;
const int N = 1e6 + 2;
int n, l1, l2, a[N], f[N], res;
vector <ii> b;

void input() {
    cin >> n >> l1 >> l2;
    for (int i = 1;i <= n;i++) cin >> a[i];
}

priority_queue <ii> hd;

void proc2() {
    for (int i = 1;i <= n;i++) {
        if (i-l1 > 0) hd.push(ii(f[i-l1], i- l1));
        while (!hd.empty()) {
            if (hd.top().second < i - l2) hd.pop();
            else break;
        }
        f[i] = hd.top().first + a[i];
        res = max(f[i], res);
    }
    cout << res << "\n";
}

void proc() {
    for (int i = 1;i <= n;i++) {
        f[i] = a[i];
        while (!b.empty()) {
            if (b.back().second < i - l2) b.pop_back();
            else break;
        }
        if (i - l1 > 0) {
            if (b.empty()) b.push_back(ii(f[i-l1], i- l1));
            else if (b.back().first < f[i - l1]) b.push_back(ii(f[i - l1], i- l1));
        }
        if (!b.empty()) f[i] += b.back().first;
        res = max(res, f[i]);
    }
    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    proc();
    return 0;
}