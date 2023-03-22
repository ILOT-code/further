// UVa 1354
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 6 + 2;
double d, w[maxn], l[maxn], r[maxn];
int T, n, vis[maxn];
double ans;

void dfs(int cur) {
    if (cur == n) {
        for (int i = 0; i < n; ++i) {
            if (vis[i]) continue;
            if (l[i] + r[i] > d) break;
            ans = max(ans, l[i] + r[i]);
        }
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (vis[i]) continue;
        vis[i] = 1;
        for (int j = 0; j < n; ++j) {
            if (j == i || vis[j]) continue;
            double tmpl = l[j], tmpr = r[j];
            double a = w[j] / (w[i] + w[j]), b = 1 - a;
            w[j] += w[i];
            l[j] = max(a + l[i], -b + l[j]);
            r[j] = max(b + r[j], -a + r[i]);
            dfs(cur + 1);
            w[j] -= w[i];
            l[j] = tmpl, r[j] = tmpr;
        }
        vis[i] = 0;
    }
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%lf%d", &d, &n);
        for (int i = 0; i < n; ++i) scanf("%lf", &w[i]);
        memset(l, 0, sizeof(l));
        memset(r, 0, sizeof(r));
        memset(vis, 0, sizeof(vis));
        ans = -1;
        dfs(1);
        printf("%.10lf\n", ans);
    }
    return 0;
}