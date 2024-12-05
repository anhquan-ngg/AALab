//
// Created by Quannn on 11/2/2024.
//
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int t, n, c;
int a[N];

bool check(int distance) {
    int cnt = 1;
    int i = 1, j = 2;
    while (i < n) {
        while ((j <= n) && (a[j] - a[i] < distance)) j++;
        if (j <= n) cnt++;
        if (cnt >= c) return true;
        i = j;
        j++;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> c;
        for (int i = 1;i <= n;i++) {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        int l = 0, r = a[n] - a[1];
        while (l <= r) {
            int m = (l + r) / 2;
            if (check(m)) l = m + 1;
            else r = m - 1;
        }
        cout << r << endl;
    }
    return 0;
}
