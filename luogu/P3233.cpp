#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

const int maxn = 3e5 + 10;
const int INF = 0x3f3f3f3f;

struct Graph {
    int cnt, head[maxn], nxt[2 * maxn], to[2 * maxn];
    Graph() {
        cnt = 0;
        memset(head, -1, sizeof(head));
    }
    void add_edge(int u, int v) {
        to[cnt] = v, nxt[cnt] = head[u], head[u] = cnt++;
        to[cnt] = u, nxt[cnt] = head[v], head[v] = cnt++;
    }
} g1, g2;
int n, m, T, ind;
int d[maxn], f[maxn][20], lg2[maxn], dfn[maxn], sons[maxn];
int h[maxn], tmp[maxn], ans[maxn], dp[maxn], g[maxn];
int sta[maxn], top, is[maxn];
void initdfs(int u) {
    dfn[u] = ++ind, sons[u] = 1;
    for (int i = g1.head[u]; ~i; i = g1.nxt[i]) {
        int v = g1.to[i];
        if (v == f[u][0]) continue;
        f[v][0] = u, d[v] = d[u] + 1;
        for (int j = 1; j <= lg2[d[v]]; ++j) f[v][j] = f[f[v][j - 1]][j - 1];
        initdfs(v);
        sons[u] += sons[v];
    }
}

int cal_lca(int x, int y) {
    if (d[x] < d[y]) swap(x, y);
    while (d[x] > d[y]) x = f[x][lg2[d[x] - d[y]]];
    if (x == y) return x;
    for (int i = lg2[d[x]]; i >= 0; --i)
        if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
    return f[x][0];
}
bool cmp(int x, int y) { return dfn[x] < dfn[y]; }

void build() {
    sort(h, h + m, cmp);
    sta[top = 1] = h[0], g2.cnt = 0;
    for (int i = 1; i < m; ++i) {
        int lca = cal_lca(h[i], sta[top]);
        while (top > 1 && d[lca] < d[sta[top - 1]])
            g2.add_edge(sta[top - 1], sta[top]), --top;
        if (d[lca] < d[sta[top]]) g2.add_edge(lca, sta[top]), --top;
        if (top == 0 || sta[top] != lca) sta[++top] = lca;
        sta[++top] = h[i];
    }
    while (top > 1) g2.add_edge(sta[top - 1], sta[top]), --top;
}
void cal(int x, int y) {
    int p = y;
    for (int i = lg2[d[y] - d[x]]; i >= 0; --i) {
        int ylen = d[y] - d[f[p][i]] + dp[y], xlen = d[f[p][i]] - d[x] + dp[x];
        if (ylen < xlen || (ylen == xlen && g[y] < g[x])) p = f[p][i];
    }
    ans[g[y]] += sons[p] - sons[y];
    ans[g[x]] -= sons[p];
}
void dfs1(int p, int fa) {
    dp[p] = INF;
    for (int i = g2.head[p]; ~i; i = g2.nxt[i]) {
        int v = g2.to[i];
        if (v == fa) continue;
        dfs1(v, p);
        int dis = d[v] - d[p];
        if (dis + dp[v] < dp[p])
            dp[p] = dis + dp[v], g[p] = g[v];
        else if (dis + dp[v] == dp[p])
            g[p] = min(g[p], g[v]);
    }
    if (is[p]) g[p] = p, dp[p] = 0;
}

void dfs2(int p, int fa) {
    for (int i = g2.head[p]; ~i; i = g2.nxt[i]) {
        int v = g2.to[i];
        if (v == fa) continue;
        int dis = d[v] - d[p];

        if (dis + dp[p] < dp[v])
            dp[v] = dis + dp[p], g[v] = g[p];
        else if (dis + dp[p] == dp[v])
            g[v] = min(g[v], g[p]);
        cal(p, v);
        dfs2(v, p);
    }
    ans[g[p]] += sons[p];
    is[p] = 0, g2.head[p] = -1;
}
int main() {
    lg2[1] = 0;
    for (int i = 2; i < maxn; i++) lg2[i] = lg2[i >> 1] + 1;
    scanf("%d", &n);
    for (int i = 1, a, b; i < n; ++i) {
        scanf("%d%d", &a, &b);
        g1.add_edge(a, b);
    }
    d[1] = 1, initdfs(1);
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &m);
        for (int i = 0; i < m; ++i)
            scanf("%d", &h[i]), ans[h[i]] = 0, tmp[i] = h[i], is[h[i]] = 1;
        bool flag = is[1];
        if (!flag) h[m++] = 1;
        build();
        dfs1(1, 0), dfs2(1, 0);
        if (!flag)
            for (int i = 0; i < m - 1; ++i) printf("%d ", ans[tmp[i]]);
        else
            for (int i = 0; i < m; ++i) printf("%d ", ans[tmp[i]]);
        printf("\n");
    }
    return 0;
}