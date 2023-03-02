// UVA 11464
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 15;
const int INF = 0x3f3f3f3f;
int T, kase, n, a[maxn][maxn], b[maxn][maxn];

int solve(int s) {
    int ret = 0;
    memset(b, 0, sizeof(b));
    for (int i = 0; i < n; ++i) {
        b[0][i] = s & 1;
        s >>= 1;
        if (!b[0][i] && a[0][i]) return INF;
    }
    for (int i = 1; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            int t = 0;
            if (i > 1) t += b[i - 2][j];
            if (j > 0) t += b[i - 1][j - 1];
            if (j < n - 1) t += b[i - 1][j + 1];
            b[i][j] = t % 2;
            if (!b[i][j] && a[i][j]) return INF;
        }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) ret += a[i][j] ^ b[i][j];
    return ret;
}

int main() {
    scanf("%d", &T);
    while (++kase <= T) {
        scanf("%d", &n);
        int ans = INF;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) scanf("%d", &a[i][j]);

        for (int s = 0; s < (1 << n); ++s) ans = min(ans, solve(s));

        printf("Case %d: %d\n", kase, ans == INF ? -1 : ans);
    }
    return 0;
}