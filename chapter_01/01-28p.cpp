// UVa 10891
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 100 + 5;
int n, a[maxn], sum[maxn], d[maxn][maxn], f[maxn][maxn], g[maxn][maxn];
int main() {
    while (~scanf("%d", &n) && n) {
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), sum[i] = sum[i - 1] + a[i];
        for (int i = 1; i <= n; ++i) d[i][i] = f[i][i] = g[i][i] = a[i];
        for (int len = 2; len <= n; ++len)
            for (int i = 1; i <= n + 1 - len; ++i) {
                int j = i + len - 1;
                int res = min(f[i][j - 1], g[i + 1][j]);
                res = min(0, res);
                d[i][j] = sum[j] - sum[i - 1] - res;
                f[i][j] = min(f[i][j - 1], d[i][j]);
                g[i][j] = min(g[i + 1][j], d[i][j]);
            }
        printf("%d\n", 2 * d[1][n] - sum[n]);
    }
    return 0;
}