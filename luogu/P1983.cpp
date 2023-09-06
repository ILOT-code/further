#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1000 + 5;
int n, M, st[maxn];
bool is[maxn];
int G[maxn][maxn], f[maxn];

int dfs(int u) {
    if (f[u]) return f[u];
    f[u] = 1;
    for (int v = 1; v <= n; ++v)
        if (G[u][v]) f[u] = max(f[u], 1 + dfs(v));
    return f[u];
}

int main() {
    scanf("%d%d", &n, &M);
    for (int i = 0, s; i < M; ++i) {
        memset(is, 0, sizeof(is));
        scanf("%d", &s);
        for (int j = 0; j < s; ++j) scanf("%d", &st[j]), is[st[j]] = true;
        for (int j = st[0]; j < st[s - 1]; ++j)
            if (!is[j])
                for (int k = 0; k < s; ++k) G[j][st[k]] = 1;
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) dfs(i), ans = max(ans, f[i]);

    printf("%d\n", ans);
    return 0;
}