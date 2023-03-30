#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

const int maxn = 1000 + 5;
struct States {
    bool vis;
    string s;
} d[maxn][maxn];
string s;

string strmin(string& s1, string& s2) {
    if (s1.length() > s2.length()) return s1;
    if (s1.length() < s2.length()) return s2;
    if (s1 < s2) return s1;
    return s2;
}
string dp(int l, int r) {
    if (d[l][r].vis) return d[l][r].s;
    d[l][r].vis = 1;
    if (l == r) return d[l][r].s = string(1, s[l]);
    if (l > r) return d[l][r].s = "";

    string s1 = dp(l + 1, r), s2 = dp(l, r - 1);
    d[l][r].s = strmin(s1, s2);
    if (s[l] == s[r]) {
        string s3 = string(1, s[l]) + dp(l + 1, r - 1) + string(1, s[r]);
        d[l][r].s = strmin(d[l][r].s, s3);
    }
    return d[l][r].s;
}

int main() {
    while (cin >> s) {
        int n = s.length();
        for (int i = 0; i < n; ++i)
            for (int j = i; j < n; ++j) d[i][j].vis = 0;
        cout << dp(0, n - 1) << endl;
    }
    return 0;
}