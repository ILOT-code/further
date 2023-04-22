// UVa 1362
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 300 + 5;
const int mod = 1e9;
int d[maxn][maxn];
char s[maxn];

int dp(int l, int r) {
    if (d[l][r] != -1) return d[l][r];
    if (l == r) return d[l][r] = 1;
    if (s[l] != s[r]) return d[l][r] = 0;

    d[l][r] = 0;
    for (int k = l + 2; k <= r; ++k)
        if (s[k] == s[r]) d[l][r] = (d[l][r] + 1LL * dp(l + 1, k - 1) * dp(k, r)) % mod;

    return d[l][r];
}

int main() {
    while (~scanf("%s", s)) {
        memset(d, -1, sizeof(d));
        printf("%d\n", dp(0, strlen(s) - 1));
    }
    return 0;
}