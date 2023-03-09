// UVa 10635
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 250 * 250 + 1;
int T, kase, n, p, q;
int a[maxn], table[maxn];
int g[maxn], d[maxn];
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &n, &p, &q);
        memset(table, 0, sizeof(table));
        for (int i = 1, x; i <= p + 1; ++i) scanf("%d", &x), table[x] = i;
        int cnt = 0;
        for (int i = 1, x; i <= q + 1; ++i) {
            scanf("%d", &x);
            if (table[x]) a[cnt++] = table[x];
        }
        int ans = 0;
        for (int i = 1; i <= cnt; ++i) g[i] = INF;
        for (int i = 0; i < cnt; ++i) {
            int k = lower_bound(g + 1, g + 1 + cnt, a[i]) - g;
            d[i] = k;
            g[k] = a[i];
            ans = max(ans, d[i]);
        }
        printf("Case %d: %d\n", ++kase, ans);
    }
    return 0;
}