#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 25 + 5;
const int maxt = 20 * 12;
int n, h, f[maxn], d[maxn], t[maxn], ans;
int a[maxn][maxt];

int main() {
    scanf("%d%d", &n, &h);
    h *= 12;
    for (int i = 1; i <= n; ++i) scanf("%d", &f[i]);
    for (int i = 1; i <= n; ++i) scanf("%d", &d[i]);
    for (int i = 1; i < n; ++i) scanf("%d", &t[i]);

    memset(a, -1, sizeof(a));
    a[0][0] = 0;

    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= h; ++j) {
            for (int k = 0; k <= j - t[i - 1]; ++k)
                if ((k - 1) * d[i] < f[i] && a[i - 1][j - t[i - 1] - k] != -1) a[i][j] = max(a[i][j], a[i - 1][j - t[i - 1] - k] + k * f[i] - k * (k - 1) / 2 * d[i]);
            ans = max(ans, a[i][j]);
        }
    printf("%d\n", ans);
    return 0;
}