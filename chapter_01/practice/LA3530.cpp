// UVa 1366
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 500 + 5;
int n, m, a[maxn][maxn], b[maxn][maxn], d[maxn][maxn], suma[maxn][maxn], sumb[maxn][maxn];
int main() {
    while (~scanf("%d%d", &n, &m) && n && m) {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) scanf("%d", &a[i][j]), suma[i][j] = suma[i][j - 1] + a[i][j];
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) scanf("%d", &b[i][j]), sumb[i][j] = sumb[i - 1][j] + b[i][j];

        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) d[i][j] = max(d[i - 1][j] + suma[i][j], d[i][j - 1] + sumb[i][j]);

        printf("%d\n", d[n][m]);
    }
    return 0;
}