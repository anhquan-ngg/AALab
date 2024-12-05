#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int LOG = 20;

int n, m;
int a[N];
int st[LOG][N];

void input() {
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> a[i];
    }
}

void preprocess() {
    for (int i = 0;i < n;i++) {
        st[0][i] = i;
    }
    for (int j = 1;(1 << j) <= n;j++) {
        for (int i = 0;i + (1 << j) - 1 < n;i++) {
            if (a[st[j - 1][i]] < a[st[j - 1][i+(1 << (j-1))]]) {
                st[j][i] = st[j-1][i];
            } else {
                st[j][i] = st[j-1][i+(1 << (j-1))];
            }
        }
    }
}

int  rmq(int i, int j) {
    int k = log2(j-i+1);
    if (a[st[k][i]] <= a[st[k][j - (1 << k) + 1]]){
      return st[k][i];
    } else {
      return st[k][j - (1 << k) + 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int res = 0;
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> a[i];
    }
    preprocess();
    cin >> m;
    for (int i = 0;i < m;i++){
        int u, v;
        cin >> u >> v;
        res += a[rmq(u, v)] ;
    }
    cout << res << '\n';
}