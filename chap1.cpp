//
// Created by Quannn on 9/16/2024.
//
#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;


// int main() {
//     vector<int> V;
//     V.push_back(1);
//     V.push_back(2);
//     for (int i = 3;i <= 10;i++) {
//         V.push_back(i);
//     }
//     for (int i = 0;i < V.size();i++) {
//         cout << V[i] << " ";
//     }
//     cout << endl;
//     V.erase(V.begin(), V.begin() + 2);
//     for (int i = 0;i < V.size();i++) {
//         cout << V[i] << " ";
//     }
//     return 0;
// }

// int main() {
//     list<int> L;
//     for(int i = 1;i <= 5;i++) L.push_back(i);
//     list<int>::iterator p;
//     p = L.begin();
//     advance(p, 2);
//     L.insert(p, 2, 6);
//     for(p = L.begin(); p != L.end(); p++) {
//         cout << *p << " ";
//     }
// }

// int main() {
//     string s1 = "Hello";
//     string s2 = s1 + " World";
//     cout << "s1 = " << s1 << ", s2 = " << s2 << endl;
//     string ss = s2.substr(2,6);
//     cout << "s2 = " << s2 << ", length = " << s2.length() << endl;
//     cout << "s2.substr(2, 6) = " << ss << endl;
//     s2.replace(6, 5, "abc");
//     cout << "new s2 = " << s2 << endl;
// }

// int main() {
//     stack<int> S;
//     for (int i = 1;i <= 5;i++) {
//         S.push(i);
//         cout << "PUSH " << i << endl;
//     }
//     while (!S.empty()) {
//         cout << "POP " << S.top() << endl;
//         S.pop();
//     }
// }

// int main() {
//     queue<int> Q;
//     for (int i = 1;i <= 5;i++) {
//         Q.push(i);
//         cout << "Queue push " << i << endl;
//     }
//     while (!Q.empty()) {
//         cout << "Queue pop " << Q.front() << endl;
//         Q.pop();
//     }
// }

// int main() {
//     set<string> S;
//     S.insert("abc");
//     S.insert("def");
//     S.insert("xyz");
//     string s1 = "def";
//
//     set<string>::iterator p;
//     p = S.find(s1);
//     if (p == S.end()) cout << "String " << s1 << " does not exist" << endl;
//     else cout << "String " << s1 << " exists in "<< *p << endl;
// }

// upper_bound(k): trả về con trỏ đến phần tử nhỏ nhất mà lớn hơn k trong tập hợp.
// Nếu k lớn hơn hoặc phần tử lớn nhất trong tập hợp thì hàm trả về con trỏ đến vị trí sau phần tử cuối cùng của tập hợp

// int main() {
//     set<int> S;
//     for (int i = 1;i <= 5;i++) {
//         S.insert(2 * i);
//     }
//     set<int>::iterator p = S.upper_bound(3);
//     cout << "upper_bound(3) = " << *p << endl;
//     p = S.upper_bound(4);
//     cout << "upper_bound(4) = " << *p << endl;
//     p = S.upper_bound(10);
//     if (p == S.end()) cout << "no upper_bound of 10" << endl;
// }

// lower_bound(k): trả về con trỏ đến phần tử có giá trị bằng k (nếu k thuộc tập hợp)
// hoặc phần tử nhỏ nhất mà lớn hơn k trong tập hợp (nếu k không thuộc tập hợp)
// Nếu k lớn hơn phần tử lớn nhất thì hàm trả về con trỏ đến vị trí sau phần tử cuối cùng của tập hợp.

// int main() {
//     map<string, int> M;
//     M["abc"] = 1;
//     M["def"] = 2;
//     M["xyzt"] = 10;
//     string k = "abc";
//     cout << "value of key " << k << " is " << M[k] << endl;
//     for (map<string, int>::iterator p = M.begin();p != M.end();p++) {
//         cout << p -> first << " is mapped to value " << p->second << endl;
//     }
//     string k1 = "1234";
//     cout << "value of " << k1 << " = " << M[k1] << endl;
// }

// int main() {
//     priority_queue<int> PQ;
//     PQ.push(5);
//     PQ.push(1);
//     PQ.push(100);
//     PQ.push(30);
//     while (!PQ.empty()) {
//         int e = PQ.top(); PQ.pop();
//         cout << "PQ pop " << e << endl;
//     }
//     // Pop các phần tử theo thứ tự giảm dần
// }

int main() {
    priority_queue<pii, vector<pii>, greater<pii>> PQ;
    PQ.push(make_pair(4, -40));
    PQ.push(make_pair(1, -10));
    PQ.push(make_pair(9, -900));
    while (!PQ.empty()) {
        pii e = PQ.top(); PQ.pop();
        cout << "PQ pop (" << e.first << ", " << e.second << ")" << endl;
    }
}