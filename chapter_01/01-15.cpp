// UVa 1267
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 1000 + 5;
int T, n, s, k, maxd, fa[maxn];
bool cov[maxn];
vector<int> g[maxn], nodes[maxn];

void build(int u, int f, int d) {
    fa[u] = f;
    if (g[u].size() == 1 && d > k) {
        nodes[d].push_back(u);
        maxd = max(maxd, d);
        cov[u] = false;
    }
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if (v != f) build(v, u, d + 1);
    }
}

void dfs(int u, int f, int d) {
    if (d > k) return;
    cov[u] = true;
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if (v != f) dfs(v, u, d + 1);
    }
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &n, &s, &k);
        maxd = 0;
        for (int i = 1; i <= n; ++i) g[i].clear(), nodes[i].clear(), cov[i] = true;
        for (int i = 0, u, v; i < n - 1; ++i) {
            scanf("%d%d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        build(s, 0, 0);
        int ans = 0;
        for (int d = maxd; d > k; --d)
            for (int i = 0; i < nodes[d].size(); ++i) {
                int u = nodes[d][i], v = u;
                if (cov[u]) continue;
                for (int j = 0; j < k; ++j) v = fa[v];
                dfs(v, 0, 0);
                ans++;
            }
        printf("%d\n", ans);
    }
    return 0;
}