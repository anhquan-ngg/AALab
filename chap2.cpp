//
// Created by Quannn on 9/17/2024.
//
#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+5;

// Prefix sum 1-d array

// int n, Q;
// int a[N];
// int S[N];
//
// void prefix() {
//     S[0] = 0;
//     for (int i = 1;i <= n;i++) {
//         S[i] = S[i-1] + a[i];
//     }
// }
//
// void solve() {
//     cin >> n;
//     for (int i = 1; i <= n; i++) {
//         cin >> a[i];
//     }
//     prefix();
//     cin >> Q;
//     int u, v;
//     for (int i = 1;i <= Q;i++) {
//         cin >> u >> v;
//         cout << S[v] - S[u - 1] << endl;
//     }
// }

// prefix sum with 2-d array
// int n, m, Q;
// int a[N][N];
// int S[N][N];
//
// void prefix() {
//     for (int i = 0;i <= n;i++) {
//         S[i][0] = 0;
//     }
//     for (int j = 0;j <= m;j++) {
//         S[0][j] = 0;
//     }
//     for (int i = 1;i <=n;i++) {
//         for (int j = 1;j <= m;j++) {
//             S[i][j] = S[i-1][j] + S[i][j-1] + S[i-1][j-1] + a[i][j] << endl;
//         }
//     }
// }
//
// void solve() {
//     cin >> n >> m;
//     for (int i = 1;i <= n;i++) {
//         for (int j = 1;j <= m;j++) {
//             cin >> a[i][j];
//         }
//     }
//     prefix();
//     cin >> Q;
//     int a, b, c, d;
//     for (int i = 1;i <= Q;i++) {
//         cin >> a >> b >> c >> d;
//         cout << S[c][d] - S[c][b-1] - S[a-1][d] + S[a-1][b-1];
//     }
// }

// 2 con trỏ

int n, Q;
int a[N];
//
// void solve() {
//     cin >> n;
//     for (int i = 1;i <= n;i++) {
//         cin >> a[i];
//     }
//     cin >> Q;
//     int res = 0;
//     int i = 0, j = n;
//     while (i < j) {
//         if (a[i] + a[j] == Q) {
//             res++;
//             i++;
//             j--;
//         }
//         else if (a[i] + a[j] < Q) i++;
//         else j--;
//     }
//     cout << res << endl;
// }

// void solve() {
//     cin >> n;
//     for (int i = 1;i <= n;i++) {
//         cin >> a[i];
//     }
//     cin >> Q;
//     int res = 0, S = 0;
//     int l = 1;
//     for (int r = 1;r <= n;r++) {
//         S += a[r];
//         if (S > Q) {
//             S -= a[l];
//             l++;
//         }
//         res = max(res, r - l + 1);
//     }
//
//     cout << res << endl;
// }


// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     solve();
// }