#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
#include <string>
using namespace std;

const int maxn = 120000 + 5;
string s[maxn];
set<string> vis;

int main() {
    int n = 0;
    while (cin >> s[n]) vis.insert(s[n++]);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < s[i].length(); ++j) {
            string t1 = s[i].substr(0, j);
            string t2 = s[i].substr(j);
            if (vis.count(t1) && vis.count(t2)) {
                cout << s[i] << endl;
                break;
            }
        }
    }
    return 0;
}