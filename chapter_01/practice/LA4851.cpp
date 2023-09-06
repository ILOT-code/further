// UVa 1468
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 60000 + 5;
int T, n, M, d[maxn];
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &M, &n);
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if (x1 > x2) swap(x1, x2);
        d[x1] = d[x2] = 0;
        for (int i = x1 + 1; i < x2; ++i) d[i] = M + 1;
        for (int i = 2, x, y; i < n; ++i) {
            scanf("%d%d", &x, &y);
            d[x] = min(d[x], abs(y - y1));
        }
        for (int i = x2 - 1; i >= x1; --i) d[i] = min(d[i], d[i + 1] + 1);
        for (int i = x1 + 1; i <= x2; ++i) d[i] = min(d[i], d[i - 1] + 1);
        long long ans = 0;
        for (int i = x1; i <= x2; ++i)
            if (d[i]) {
                ans++;
                ans += min(d[i] - 1, M - y1 - 1);
                ans += min(d[i] - 1, y1);
            }
        printf("%lld\n", ans);
    }
    return 0;
}