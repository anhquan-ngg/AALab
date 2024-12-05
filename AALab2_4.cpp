// LAB.02.04 - Capacitance Vehicle Routing

// A fleet of K identical trucks having capacity Q need to be scheduled to delivery pepsi packages from a central depot 0 to clients 1,2,…,n. Each client i requests d[i] packages. The distance from location i to location j is c[i,j], 0≤i,j≤n. A delivery solution is a set of routes: each truck is associated with a route, starting from depot, visiting some clients and returning to the depot for deliverying requested pepsi packages such that:
// Each client is visited exactly by one route
// Total number of packages requested by clients of each truck cannot exceed its capacity
// Goal
// Find a solution having minimal total travel distance
// Note that:
// There might be the case that a truck does not visit any client (empty route)
// The orders of clients in a route is important, e.g., routes 0 -> 1 -> 2 -> 3 -> 0 and 0 -> 3-> 2 -> 1 -> 0 are different.
// Input
// Line 1: n,K,Q (2≤n≤12,1≤K≤5,1≤Q≤50)
// Line 2: d[1],...,d[n](1≤d[i]≤10)
// Line i+3 (i=0,…,n): the i
// th
//  row of the distance matrix c (1≤c[i,j]≤30)
// Output
// Minimal total travel distance
// Example
// Input
// 4 2 15
// 7 7 11 2
// 0 12 12 11 14
// 14 0 11 14 14
// 14 10 0 11 12
// 10 14 12 0 13
// 10 13 14 11 0
//
// Output
// 70

// #include<bits/stdc++.h>
// using namespace std;
//
// const int N = 13;
// int n, K, Q;
// int d[N]; // requested packages from n clients
// int c[N][N]; // c[i][j] is distance from location i to location j
// int using_truck = 0;
// int y[6]; // y[i] is first client of truck i
// int x[N]; // x[i] is the next location of location i
// int cmin = INT_MAX;
// int visited[N] = {0};
// int load[6] = {0};
// int segments = 0;
// int res, f_res;
//
//
// void input() {
//     cin >> n >> K >> Q;
//     for (int i = 1;i <= n;i++) {
//         cin >> d[i];
//     }
//     for (int i = 0;i <= n;i++) {
//         for (int j = 0;j <= 2*n;j++) {
//             cin >> c[i][j];
//             if (c[i][j] != 0) {
//                 cmin = min(c[i][j], cmin);
//             }
//         }
//     }
// }
//
// int checkX(int v, int k) {
//     if (v > 0 && visited[v] == 1) return 0;
//     if (load[k] + d[v] > Q) return 0;
//     return 1;
// }
//
// int checkY(int v, int k) {
//     if (v == 0) return 1;
//     if (load[k] + d[v] > Q) return 0;
//     if (visited[v]) return 0;
//     return 1;
// }
//
// void  Try_X(int s, int k) {
//     if (s == 0) {
//         if (k < K) Try_X(y[k+1], k + 1);
//         f_res = min(f_res,  res);
//         return;
//     }
//     for (int i = 0;i <= n;i++) {
//         if (checkX(i, k)) {
//             x[s] = i;
//             visited[i] = 1;
//             load[k] += d[i];
//             res += c[s][i];
//             segments++;
//             if (i > 0) {
//                 if (res + (n + using_truck - segments)*cmin < f_res) {
//                     Try_X(i, k);
//                 }
//             } else {
//                 if (res + (n + using_truck - segments)*cmin < f_res) {
//                     Try_X(y[k+1], k+1);
//                 }
//             }
//             segments--;
//             res -= c[s][i];
//             load[k] -= d[i];
//             visited[i] = 0;
//         }
//     }
// }
//
// void Try_Y(int k) {
//     int s = 0;
//     if (y[k - 1] > 0) s = y[k - 1] + 1;
//     for (int i = s;i <= n;i++) {
//         if (checkY(i, k)) {
//             if (i > 0) segments++;
//             y[k] = i;
//             visited[i] = 1;
//             load[k] += d[i];
//             res += c[0][i];
//             if (k < K) Try_Y(k+1);
//             else {
//                 using_truck = segments;
//                 Try_X(y[1],1);
//             }
//             res -= c[0][i];
//             load[k] -= d[i];
//             visited[i] = 0;
//             if (i > 0) segments--;
//         }
//     }
//
// }
//
// void solve() {
//     res = 0;
//     f_res = INT_MAX;
//     y[0] = 0;
//     Try_Y(1);
//     cout << f_res << endl;
// }
//
// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     input();
//     solve();
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

const int N = 20;
const int oo = 1e9;
int n, K, Q, cmin = oo;
int d[N], C[N][N];
int x[N], y[N], load[N];
int segments = 0, f = 0, fOpt = oo, nbR;
bool visited[N];

void input() {
    cin >> n >> K >> Q;
    for (int i = 1; i <= n; i++)
        cin >> d[i];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++) {
            cin >> C[i][j];
            if (i != j) cmin = min(cmin, C[i][j]);
        }
}

bool checkY(int v, int k) {
    if (v == 0) return true;
    if (d[v] > Q) return false;
    if (visited[v]) return false;
    return true;
}

bool checkX(int v, int k) {
    if (v > 0 && visited[v]) return false;
    if (load[k] + d[v] > Q) return false;
    return true;
}

void updateBest() {
    if (f < fOpt) fOpt = f;
}

void TRY_X(int s, int k) {
    if (s == 0) {
        if (k < K) TRY_X(y[k + 1], k + 1);
        return;
    }

    for (int v = 0; v <= n; v++) {
        if (checkX(v, k)) {
            x[s] = v;
            visited[v] = true;
            f += C[s][v];
            segments++;
            load[k] += d[v];
            if (v > 0) {
                if (f + (n + nbR - segments) * cmin < fOpt)
                    TRY_X(v, k);
            } else {
                if (k == K) {
                    if (segments == n + nbR) updateBest();
                } else {
                    if (f + (n + nbR - segments) * cmin < fOpt)
                        TRY_X(y[k + 1], k + 1);
                }
            }
            visited[v] = false;
            f -= C[s][v];
            segments--;
            load[k] -= d[v];
        }
    }
}

void TRY_Y(int k) {
    int s = 0;
    if (y[k - 1] > 0) s = y[k - 1] + 1;

    for (int v = s; v <= n; v++) {
        if (checkY(v, k)) {
            y[k] = v;
            if (v > 0) segments++;
            f += C[0][v];
            visited[v] = true;
            load[k] += d[v];
            if (k < K) TRY_Y(k + 1);
            else {
                nbR = segments;
                TRY_X(y[1], 1);
            }
            if (v > 0) segments--;
            f -= C[0][v];
            visited[v] = false;
            load[k] -= d[v];
        }
    }
}

int main() {
    input();
    y[0] = 0; d[0] = 0;
    TRY_Y(1);
    cout << fOpt << endl;
    return 0;
}




