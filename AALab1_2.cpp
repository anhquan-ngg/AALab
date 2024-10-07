//
// Created by Quannn on 10/7/2024.
//
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

const int N = 1005;
int a[N][N], m, n, r, c, d[N][N];
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
queue<ii> qii;

int solve() {
    qii.push(ii(r, c));
    d[r][c] = 0; // Ma trận tính số bước
    a[r][c] = 1; // Ma trận đánh dấu đã xét qua
    while (!qii.empty()) {
        ii u = qii.front();
        qii.pop();
        for (int i = 0;i < 4;i++) {
            int x = u.first + dx[i];
            int y = u.second + dy[i];
            if (x < 1 || x > m || y < 1 || y > n) return d[u.first][u.second] + 1;
            if (a[x][y] != 1) {
                d[x][y] = d[u.first][u.second] + 1;
                qii.push(ii(x, y));
                a[x][y] = 1;
            }
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> m >> n >> r >> c;
    for(int i = 1;i <= m;i++) {
        for (int j = 1;j <= n;j++) {
            cin >> a[i][j];
        }
    }
    int res = solve();
    cout << res << endl;
    return 0;
}