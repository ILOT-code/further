#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;

const int maxn = 30 + 10;
LL f[maxn], d[maxn][maxn];

LL C(LL n, LL m) {
    double ans = 1;
    for (int i = 0; i < m; ++i) ans *= n - i;
    for (int i = 0; i < m; ++i) ans /= i + 1;
    return 1LL * (ans + 0.5);
}
int main() {
    f[1] = 1;
    int n = 30;
    for (int i = 0; i <= n; ++i) d[i][0] = 1;
    for (int i = 1; i <= n; ++i) d[i][1] = 1, d[0][i] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 2; j <= n; ++j) {
            d[i][j] = 0;
            for (int p = 0; p * i <= j; ++p) d[i][j] += C(f[i] + p - 1, p) * d[i - 1][j - p * i];
        }
        f[i + 1] = d[i][i + 1];
    }
    while (~scanf("%d", &n) && n) printf("%lld\n", n == 1 ? 1 : 2 * f[n]);
    return 0;
}