//
// Created by Quannn on 12/5/2024.
//
#include <bits/stdc++.h>
using namespace std;

const int M = 12;
const int N = 32;

int m, n;
vector<int> prefer[M];
vector<pair<int,int>> conflicts;
vector<int> assigned[M];
int maxLoad = INT_MAX;
int currLoad[M] = {0};
int courseTeacher[N] = {0};
int conflictMatrix[N][N];

int check(int c, int t){
    if (find(prefer[t].begin(), prefer[t].end(), c) == prefer[t].end()) return 0;
    for (int assignedCourse : assigned[t]){
        if (conflictMatrix[assignedCourse][c]) return 0;
    }
    return 1;
}

void Try(int idx){
    if (idx > n) {
        int currMaxLoad = *max_element(currLoad + 1, currLoad + m + 1);
        maxLoad = min(currMaxLoad, maxLoad);
        return;
    }

    for (int i = 1;i <= m;i++){
        if (check(idx, i)){
            assigned[i].push_back(idx);
            currLoad[i]++;
            courseTeacher[idx] = i;
            if(*max_element(currLoad + 1, currLoad + m + 1) < maxLoad) Try(idx+1);
            courseTeacher[idx] = 0;
            currLoad[i]--;
            assigned[i].pop_back();
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> n;
    for (int i = 1;i <= m;i++){
        int k;
        cin >> k;
        prefer[i].resize(k);
        for (int j = 0;j < k;j++){
            cin >> prefer[i][j];
        }
    }
    int k;
    cin >> k;
    conflicts.resize(k);
    memset(conflictMatrix, 0, sizeof(conflictMatrix));
    for (int i = 0;i < k;i++){
        int u, v;
        cin >> u >> v;
        conflicts[i] = {u, v};
        conflictMatrix[u][v] = conflictMatrix[v][u] = 1;
    }
    Try(1);
    if (maxLoad == INT_MAX) cout << -1 << endl;
    else cout << maxLoad << endl;
    return 0;
}




