#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

const int maxn = 50 + 5;
int n;
string c[maxn];

bool cmp(string x, string y) { return x + y > y + x; }
int main() {
    while (scanf("%d", &n) && n) {
        for (int i = 0; i < n; ++i) cin >> c[i];
        sort(c, c + n, cmp);
        for (int i = 0; i < n; ++i) cout << c[i];
        cout << endl;
    }
    return 0;
}