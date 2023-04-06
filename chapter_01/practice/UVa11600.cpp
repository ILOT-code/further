#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

const int maxn = 30 + 5;
int T, kase, n, m, cnt, vis[maxn], num[maxn];
map<int, double> f;
vector<int> g[maxn];

int dfs(int u) {
    int count = 1;
    vis[u] = 1;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (!vis[v]) count += dfs(v);
    }
    return count;
}

double dp(int s) {
    if (f.count(s)) return f[s];
    int sum = 0;
    for (int i = 0; i < cnt; i++)
        if (s & (1 << i)) sum += num[i];
    if (sum == n) return f[s] = 0;

    f[s] = (n - 1) * 1.0 / (n - sum);
    for (int i = 0; i < cnt; i++)
        if (!(s & (1 << i))) f[s] += dp(s | (1 << i)) * num[i] * 1.0 / (n - sum);
    return f[s];
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i <= n; i++) g[i].clear(), vis[i] = num[i] = 0;
        f.clear();
        for (int i = 0, u, v; i < m; i++) {
            scanf("%d%d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        cnt = 0;
        for (int i = 1; i <= n; ++i)
            if (!vis[i]) num[cnt++] = dfs(i);
        printf("Case %d: %lf\n", ++kase, dp(1));
    }
    return 0;
}