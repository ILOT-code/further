#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 100 + 5;
const int INF = 0x3f3f3f3f;
int kase, n, k, d[2][maxn][1 << 8][10];

int bitcount(int s) { return s == 0 ? 0 : bitcount(s >> 1) + (s & 1); }
int main() {
    while (~scanf("%d%d", &n, &k) && (n || k)) {
        memset(d[1], INF, sizeof(d[0]));
        int t = 0, stasum = 0;
        for (int i = 1, a; i <= n; ++i) {
            scanf("%d", &a);
            a -= 25;
            memset(d[t], INF, sizeof(d[t]));
            d[t][i - 1][1 << a][a] = 1;
            for (int j = 0; j <= min(k, i - 2); ++j) {
                for (int s = stasum; s; s = (s - 1) & stasum) {
                    for (int x = 0; (1 << x) <= s; ++x) {
                        if (s & (1 << x) == 0) continue;
                        if (x == a)
                            d[t][j][s][x] = min(d[t][j][s][x], d[t ^ 1][j][s][x]);
                        else
                            d[t][j][s | (1 << a)][a] = min(d[t][j][s | (1 << a)][a], d[t ^ 1][j][s][x] + 1);

                        d[t][j + 1][s][x] = min(d[t][j + 1][s][x], d[t ^ 1][j][s][x]);
                    }
                }
            }
            stasum |= (1 << a);
            t ^= 1;
        }
        int ans = INF;
        for (int i = 0; i <= min(k, n - 1); ++i) {
            for (int s = stasum; s; s = (s - 1) & stasum) {
                for (int x = 0; (1 << x) <= s; ++x) {
                    if (s & (1 << x) == 0) continue;
                    ans = min(ans, d[t ^ 1][i][s][x] + bitcount(stasum ^ s));
                }
            }
        }
        printf("Case %d: %d\n\n", ++kase, ans);
    }
    return 0;
}