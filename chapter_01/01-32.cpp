// UVa 1099
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 16;
const int maxw = 100 + 5;
int kase, n, x, y, a[maxn], sum[1 << maxn];
bool f[1 << maxn][maxw], vis[1 << maxn][maxw];

int bitcount(int x) { return x == 0 ? 0 : bitcount(x >> 1) + (x & 1); }
int dp(int s, int x) {
    if (vis[s][x]) return f[s][x];
    vis[s][x] = 1;
    bool& ans = f[s][x];
    if (bitcount(s) == 1) return ans = 1;
    int y = sum[s] / x;
    for (int t = (s - 1) & s; t; t = (t - 1) & s) {
        int s1 = s - t;
        if (sum[t] % x == 0 && dp(t, min(x, sum[t] / x)) && dp(s1, min(x, sum[s1] / x))) return ans = 1;
        if (sum[t] % y == 0 && dp(t, min(y, sum[t] / y)) && dp(s1, min(y, sum[s1] / y))) return ans = 1;
    }
    return ans = 0;
}

int main() {
    while (~scanf("%d", &n) && n) {
        scanf("%d%d", &x, &y);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        memset(sum, 0, sizeof(sum));
        memset(vis, 0, sizeof(vis));
        for (int s = 0; s < (1 << n); ++s)
            for (int i = 0; i < n; ++i)
                if (s & (1 << i)) sum[s] += a[i];

        int all = (1 << n) - 1, ans;
        if (sum[all] != x * y) ans = 0;
        else ans = dp(all, min(x, y));
        printf("Case %d: %s\n", ++kase, ans ? "Yes" : "No");
    }
    return 0;
}