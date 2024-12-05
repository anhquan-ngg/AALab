#include<bits/stdc++.h>
using namespace std;

const int N = 12;
int n, K;

int d[2*N][2*N];
int visited[2 * N] = {0};
int min_route = INT_MAX;
int curr = 0;
int load = 0;
int cmin = INT_MAX;

void input() {
    cin >> n >> K;
    for (int i = 0;i <= (2*n);i++) {
        for (int j = 0;j <= (2*n);j++) {
            cin >> d[i][j];
            if (d[i][j] != 0) {
                cmin = min(cmin, d[i][j]);
            }
        }
    }
}

void Try(int pos, int m) {
    if (m == 2*n) {
        min_route = min(min_route, curr+d[pos][0]);
        return;
    }
    for (int i = 0; i <= (2*n); i++) {
        if (!visited[i]) {
            if (i <= n && load < K) {
                visited[i] = 1;
                curr += d[pos][i];
                load++;
                if(curr + cmin * (2 * n - m + 1) <= min_route) Try(i, m+1);
                load--;
                curr -= d[pos][i];
                visited[i] = 0;
            }
            else if (i > n && visited[i-n]) {
                visited[i] = 1;
                curr += d[pos][i];
                load--;
                if(curr + cmin * (2 * n - m + 1) <= min_route) Try(i, m+1);
                load++;
                curr -= d[pos][i];
                visited[i] = 0;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    input();
    Try(0, 0);
    cout << min_route << endl;
    return 0;
}
