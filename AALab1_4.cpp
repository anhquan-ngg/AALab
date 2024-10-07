//
// Created by Quannn on 10/7/2024.
//
#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int m, n;
int a[N][N];
int ans;
long long h[N];
stack<long long> sll;
vector<long long> vll;
long long L[N], R[N];

void input() {
    cin >> m >> n;
    for (int i = 1;i <= m;i++) {
        for(int j = 1;j <=n;j++) {
            cin >> a[i][j];
        }
    }
}

long long compute() {
    h[0] = -1; h[m+1] = -1; vll.clear();
    for (int i = 1; i <= m+1;i++) {
        while (!vll.empty() && h[i] < h[vll[vll.size() - 1]]) {
            R[vll[vll.size() - 1]] = i;
            vll.pop_back();
        }
        vll.push_back(i);
    }
    for (int i = m;i >= 0;i--) {
        while (!vll.empty() && h[i] < h[vll[vll.size() - 1]]) {
            L[vll[vll.size() - 1]] = i;
            vll.pop_back();
        }
        vll.push_back(i);
    }
    unsigned long long ans = 0;
    for (int i = 1;i <= m;i++) {
        unsigned long long c = (R[i] - L[i] - 1) * h[i];
        ans = ans < c ? c : ans;
    }
    return ans;
}

void solve() {
    long long ans = 0;
    for (int i = 1;i <= n;i++) h[i] = 0;
    for (int i = 1;i <= m;i++) {
        for (int j = 1;j <= n;j++) {
            if (a[i][j] == 0) {
                h[j] = 0;
            } else h[j] += 1;
        }
        long long t = compute();
        if (t > ans) ans = t;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    input();
    solve();
    return 0;
}