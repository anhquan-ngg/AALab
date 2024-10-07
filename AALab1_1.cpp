//
// Created by Quannn on 10/7/2024.
//
#include<bits/stdc++.h>
using namespace std;

bool checkPhone(string numphone) {
    if (numphone.length() != 10) return false;
    for (int i = 0;i < numphone.length(); i++) {
        if (numphone[i] < '0' || numphone[i] > '9') return false;
    }
    return true;
}

int countTime(string ftime, string ttime) {
    int startTime = 3600 * ((ftime[0] - '0') * 10 + ftime[1] - '0') + 60 * (10 * (ftime[3] - '0') + ftime[4] - '0') + 10 * (ftime[6] - '0') + ftime[7] - '0';
    int endTime = 3600 * ((ttime[0] - '0') * 10 + ttime[1] - '0') + 60 * (10 * (ttime[3] - '0') + ttime[4] - '0') + 10 * (ttime[6] - '0') + ttime[7] - '0';
    return endTime - startTime;
}

map <string, int> numberCalls, callTimes;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string text;
    int totalCalls = 0;
    int falseNumbers = 0;
    do {
        cin >> text;
        if (text == "#") continue;
        totalCalls++;
        string fnum, tnum, date, ftime, etime;
        cin >> fnum >> tnum >> date >> ftime >> etime;
        if (!checkPhone(fnum) ||  !checkPhone(tnum)) falseNumbers++;
        numberCalls[fnum]++;
        callTimes[fnum] += countTime(ftime, etime);
    } while (text != "#");
    do {
        cin >> text;
        if (text == "#") continue;
        if (text == "?check_phone_number") {
            if (falseNumbers == 0) {
                cout << 1 << endl;
            }
            else cout << -1 << endl;
        }
        else if (text == "?number_calls_from") {
            string number;
            cin >> number;
            cout << numberCalls[number] << endl;
        }
        else if (text == "?number_total_calls") {
            cout << totalCalls << endl;
        }
        else if (text == "?count_time_calls_from") {
            string number;
            cin >> number;
            cout << callTimes[number] << endl;
        }
    } while (text != "#");
    return 0;
}