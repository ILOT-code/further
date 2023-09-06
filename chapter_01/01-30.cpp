// UVa 10859
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 1000 + 5;
const int M = 2000;
int T, n, M, d[maxn][2];
bool vis[maxn][2];
vector<int> g[maxn];

int dp(int i, int j, int f) {
    if (vis[i][j]) return d[i][j];
    vis[i][j] = 1;
    int& ans = d[i][j];
    ans = j * M;
    for (int k = 0; k < g[i].size(); ++k)
        if (g[i][k] != f) {
            if (j == 0) ans += dp(g[i][k], 1, i) + 1;
            if (j == 1) ans += min(dp(g[i][k], 1, i), dp(g[i][k], 0, i) + 1);
        }
    return ans;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &M);
        for (int i = 0; i < n; ++i) g[i].clear();
        memset(vis, 0, sizeof(vis));
        for (int i = 0, a, b; i < M; ++i) {
            scanf("%d%d", &a, &b);
            g[a].push_back(b);
            g[b].push_back(a);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
            if (!vis[i][0] && !vis[i][1]) ans += min(dp(i, 0, -1), dp(i, 1, -1));

        printf("%d %d %d\n", ans / M, M - ans % M, ans % M);
    }
    return 0;
}