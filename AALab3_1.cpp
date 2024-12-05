//
// Created by Quannn on 11/2/2024.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> segments(n);

    // Nhập các đoạn
    for (int i = 0; i < n; i++) {
        cin >> segments[i].first >> segments[i].second;
    }

    // Sắp xếp các đoạn theo điểm kết thúc tăng dần
    sort(segments.begin(), segments.end(), [](pair<int, int> &a, pair<int, int> &b) {
        return a.second < b.second;
    });

    int count = 0;
    int end = -1;

    // Duyệt qua từng đoạn và chọn các đoạn không giao nhau
    for (auto &segment : segments) {
        if (segment.first >= end) { // Không giao với đoạn trước đó
            count++;
            end = segment.second;
        }
    }

    // Kết quả là số đoạn không giao nhau lớn nhất
    cout << count << endl;
    return 0;
}
