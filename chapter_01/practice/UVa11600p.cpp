// 超时，但没想到会慢那么多，不应该啊
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

const int maxn = 30 + 2;
int T, kase, n, m, nn;
int fa[maxn], cnt[maxn], que[maxn];
bool vis[maxn];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
map<int, double> d;

double dp(int s) {
    if (d.count(s) && d[s] > 1e-9) return d[s];
    int sum = 0;
    for (int i = 0; i < nn; ++i)
        if (s & (1 << i)) sum += cnt[que[i]];
    if (sum == n) return d[s] = 0;
    d[s] = (n - 1) * 1.0 / (n - sum);
    for (int i = 0; i < nn; ++i)
        if (!(s & (1 << i))) d[s] += dp(s | (1 << i)) * cnt[que[i]] * 1.0 / (n - sum);
    return d[s];
}

int main() {
    scanf("%d", &T);
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 1; i <= n; ++i) fa[i] = i, cnt[i] = 1, vis[i] = 0;
        d.clear();
        for (int i = 1, u, v; i <= m; ++i) {
            scanf("%d%d", &u, &v);
            if (find(u) != find(v)) {
                cnt[fa[u]] += cnt[fa[v]];
                fa[v] = u;
            }
        }
        nn = 0;
        for (int i = 1; i <= n; ++i) {
            if (!vis[find(i)]) {
                vis[fa[i]] = 1;
                que[nn++] = fa[i];
            }
        }
        printf("Case %d: %lf\n", ++kase, dp(1));
    }
    return 0;
}