// UVa 11825
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 16;
int n, kase;
int f[1 << maxn], p[maxn], cover[1 << maxn];
int main() {
    while (~scanf("%d", &n) && n) {
        for (int i = 0, m, x; i < n; ++i) {
            p[i] = 1 << i;
            scanf("%d", &m);
            for (int j = 0; j < m; ++j) scanf("%d", &x), p[i] |= 1 << x;
        }
        for (int s = 0; s < (1 << n); ++s) {
            cover[s] = 0;
            for (int i = 0; i < n; ++i)
                if (s & (1 << i)) cover[s] |= p[i];
        }
        int all = (1 << n) - 1;
        for (int s = 0; s < (1 << n); ++s) {
            f[s] = 0;
            for (int t = s; t; t = (t - 1) & s)
                if (cover[t] == all) f[s] = max(f[s], f[s ^ t] + 1);
        }
        printf("Case %d: %d\n", ++kase, f[all]);
    }
    return 0;
}