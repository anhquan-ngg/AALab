//
// Created by Quannn on 11/2/2024.
//
#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int const MOD = 1e9 + 7;
int n, a[N], temp[N];

void input(){
    cin >> n;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
    }
}

int merge(int l, int m, int r){
    int i = l,j = m + 1,k = l, cnt = 0;
    while ((i <= m) && (j <= r)){
        if (a[i] <= a[j]) temp[k++] = a[i++];
        else {
            temp[k++] = a[j++];
            cnt = (cnt + (m - i + 1)) % MOD;
        }
    }
    while (i <= m) temp[k++] = a[i++];
    while (j <= r) temp[k++] = a[j++];
    for (int i = l;i <= r;i++) a[i] = temp[i];
    return cnt;
}

int mergeSort(int l, int r){
    int m, cnt = 0;
    if (l < r){
        m = (l+r) / 2;
        cnt = (cnt + mergeSort(l, m)) % MOD;
        cnt = (cnt + mergeSort(m+1, r)) % MOD;
        cnt = (cnt + merge(l, m, r)) % MOD;
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    cout << mergeSort(1, n) << endl;
    return 0;
}
