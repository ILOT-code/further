#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 10000 + 5;
const int INF = 0x3f3f3f3f;
int n, a[maxn];
int d1[maxn], d2[maxn], g[maxn];

int main() {
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

        for (int i = 1; i <= n; ++i) g[i] = INF;
        for (int i = 0; i < n; ++i) {
            int t = lower_bound(g + 1, g + 1 + n, a[i]) - g;
            d1[i] = t;
            g[t] = a[i];
        }
        for (int i = 1; i <= n; ++i) g[i] = INF;
        for (int i = n - 1; i >= 0; --i) {
            int t = lower_bound(g + 1, g + 1 + n, a[i]) - g;
            d2[i] = t;
            g[t] = a[i];
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) ans = max(ans, 2 * min(d1[i], d2[i]) - 1);
        printf("%d\n", ans);
    }
    return 0;
}