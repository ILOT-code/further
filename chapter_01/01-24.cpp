// UVa 10755
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define REP(i, s, t) for (int i = (s); i <= (t); ++i)
typedef long long LL;

const int maxn = 20 + 5;
const LL INF = 1LL << 60;
LL s[maxn][maxn][maxn];
int T, a, b, c, b0, b1, b2;

void getd(int t, int& b0, int& b1, int& b2) {
    b0 = t & 1, t >>= 1;
    b1 = t & 1, t >>= 1;
    b2 = t & 1;
}
int sign(int b0, int b1, int b2) { return (b0 + b1 + b2) % 2 ? 1 : -1; }
LL sum(int x1, int x2, int y1, int y2, int z1, int z2) {
    int dx = x2 - x1 + 1, dy = y2 - y1 + 1, dz = z2 - z1 + 1;
    LL ret = 0;
    for (int i = 0; i < 8; ++i) {
        getd(i, b0, b1, b2);
        ret -= s[x2 - b0 * dx][y2 - b1 * dy][z2 - b2 * dz] * sign(b0, b1, b2);
    }
    return ret;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &a, &b, &c);
        REP(i, 1, a) REP(j, 1, b) REP(k, 1, c) scanf("%lld", &s[i][j][k]);
        REP(i, 1, a) REP(j, 1, b) REP(k, 1, c) REP(t, 1, 7) {
            getd(t, b0, b1, b2);
            s[i][j][k] += s[i - b0][j - b1][k - b2] * sign(b0, b1, b2);
        }
        LL ans = -INF;
        REP(x1, 1, a) REP(x2, x1, a) REP(y1, 1, b) REP(y2, y1, b) {
            LL m = 0;
            REP(z, 1, c) {
                LL ret = sum(x1, x2, y1, y2, 1, z);
                ans = max(ans, ret - m);
                m = min(m, ret);
            }
        }
        printf("%lld\n", ans);
        if (T) printf("\n");
    }
    return 0;
}