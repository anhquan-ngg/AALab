#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, m;
int a[N];
int cnt = 0;
int current_sum = 0;

void input() {
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
}

void Try(int k) {
    if (k == n + 1) {
        if (current_sum == m) {
            cnt++;
        }
        return;
    }
    for (int v = 1;current_sum + v * a[k] <= m;v++) {
        current_sum += v * a[k];
        Try(k + 1);
        current_sum -= v * a[k];
    }
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    input();
    Try(1);
    cout << cnt << "\n";
    return 0;
}