#include<bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {
    if (s.length() <= 1) {
        return s;
    }

    int max_len = 0;
    int start = 0;
    int end = 0;
    vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));

    for (int i = 0;i < s.length();i++) {
        dp[i][i] = true;
        for (int j = 0;j < i; j++) {
            if (s[i] == s[j] && (i - j <= 2 || dp[j+1][i-1])) {
                dp[i][j] = true;
                if (i - j + 1 > max_len) {
                    max_len = i - j + 1;
                    start = j;
                    end = i;
                }
            }
        }
    }
    return s.substr(start, end - start + 1);
}

int main() {
    string s;
    cin >> s;
    cout << longestPalindrome(s);
    return 0;
}