//
// Created by Quannn on 11/25/2024.
//
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 2;
int n, f[N][102], T, D, a[N], t[N], res;

void input() {
    cin >> n >> T >> D;
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1;i <= n;i++) cin >> t[i];
}

void proc() {
    for (int i = 1;i <= n;i++) {
        for (int k = t[i];k <= T;k++) {
            for (int j = max(0, i - D);j <= i-1;j++) {
                f[i][k] = max(f[i][k], f[j][k-t[i]] + a[i]);
            }
            res = max(res, f[i][k]);
        }
    }
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    proc();
    return 0;
}