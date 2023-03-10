// UVa 10891
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 100 + 5;
int n, a[maxn], sum[maxn], d[maxn][maxn];
int main() {
    while (~scanf("%d", &n) && n) {
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), sum[i] = sum[i - 1] + a[i], d[i][i] = a[i];
        for (int len = 2; len <= n; ++len)
            for (int i = 1; i <= n + 1 - len; ++i) {
                int j = i + len - 1;
                int res = 0;
                for (int k = 0; k < j - i; ++k) res = min(res, d[i][i + k]), res = min(res, d[j - k][j]);
                d[i][j] = sum[j] - sum[i - 1] - res;
            }

        printf("%d\n", 2 * d[1][n] - sum[n]);
    }
    return 0;
}