// UVa 1292
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 1500 + 5;
const int INF = 0x3f3f3f3f;
int n, fa[maxn], d[maxn][2];
vector<int> g[maxn];

void build_tree(int u, int f) {
    fa[u] = f;
    for (int i = 0; i < g[u].size(); ++i)
        if (g[u][i] != f) build_tree(g[u][i], u);
}

int dp(int u, int f) {
    int& ans = d[u][f];
    if (ans != -1) return ans;
    ans = f;
    if (f)
        for (int i = 0; i < g[u].size(); ++i) {
            int v = g[u][i];
            if (v != fa[u]) ans += min(dp(v, 0), dp(v, 1));
        }
    else
        for (int i = 0; i < g[u].size(); ++i) {
            int v = g[u][i];
            if (v != fa[u]) ans += dp(v, 1);
        }
    return ans;
}

int main() {
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) g[i].clear();
        for (int i = 0; i < n; ++i) {
            int u, v, num;
            scanf("%d:(%d)", &u, &num);
            for (int j = 0; j < num; ++j) {
                scanf("%d", &v);
                g[u].push_back(v);
                g[v].push_back(u);
            }
        }
        build_tree(0, -1);
        memset(d, -1, sizeof(d));
        printf("%d\n", min(dp(0, 0), dp(0, 1)));
    }
    return 0;
}