//
// Created by Quannn on 9/10/2024.
//

// Using Backtracking
// #include<bits/stdc++.h>
// using namespace std;
//
// using ll = long long;
// int n, arr[100][100], X[100];
// int visited[100];
// int d = 0, ans = INT_MAX;
// int cnt = 0;
//
// //X[i]: Số thứ tự thành phố thứ i mà người đó đã đi thăm
//
// void inputArr() {
//     cin >> n;
//     for (int i = 1;i <= n;i++) {
//         for (int j = 1;j <= n;j++) {
//             cin >> arr[i][j];
//         }
//     }
//
//     memset(visited, 0, sizeof(visited));
// }
//
// void Try(int i) {
//     cnt++;
//     for (int j = 1;j <= n;j++) {
//         if (visited[j] == 0) {
//             visited[j] = 1;
//             X[i] = j;
//             d += arr[X[i-1]][X[i]];
//             if (i == n) {
//                 ans = min(ans, d + arr[X[n]][X[1]]);
//             } else {
//                 Try(i+1);
//             }
//             // Backtracking
//             visited[j] = 0;
//             d -= arr[X[i-1]][X[i]];
//         }
//     }
// }
//
// int main() {
//     inputArr();
//     X[1] = 1;
//     visited[1] = 1;
//     Try(2);
//     cout << ans << endl;
//     cout << cnt << endl;
//     return 0;
// }

// Using Branch and Bound
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
int n, arr[100][100], X[100];
int visited[100];
int d = 0, ans = INT_MAX, cmin = INT_MAX;
int cnt = 0;

//X[i]: Số thứ tự thành phố thứ i mà người đó đã đi thăm

// Tối ưu: Đánh giá cận dưới: chi phí nhỏ nhất có thể đạt được trong lời gọi quay lui hiện tại

void inputArr() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            cin >> arr[i][j];
            if (arr[i][j] != 0) {
                cmin = min(cmin, arr[i][j]);
            }
        }
    }

    memset(visited, 0, sizeof(visited));
}

void Try(int i) {
    cnt++;
    for (int j = 1;j <= n;j++) {
        if (visited[j] == 0) {
            visited[j] = 1;
            X[i] = j;
            d += arr[X[i-1]][X[i]];
            if (i == n) {
                ans = min(ans, d + arr[X[n]][X[1]]);
            } else if (d + (n - i + 1) * cmin < ans) {
                Try(i+1);
            }
            // Backtracking
            visited[j] = 0;
            d -= arr[X[i-1]][X[i]];
        }
    }
}

int main() {
    inputArr();
    X[1] = 1;
    visited[1] = 1;
    Try(2);
    cout << ans << endl;
    cout << cnt << endl;
    return 0;
}
