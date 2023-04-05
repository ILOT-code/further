// UVa 1407
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 500 + 5;
const int INF = 0x3f3f3f3f;
int kase, n, q, x;
int dis[maxn], d[maxn][maxn][2], cnt[maxn];
vector<int> g[maxn];

void dp(int u) {
    cnt[u] = 1;
    for (int i = 0; i < g[u].size(); ++i) {
        dp(g[u][i]);
        cnt[u] += cnt[g[u][i]];
    }
    d[u][1][0] = d[u][1][1] = 0;
    for (int i = 2; i <= cnt[u]; ++i) d[u][i][0] = d[u][i][1] = INF;

    int sum = 1;
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        sum += cnt[v];
        for (int j = sum; j >= 2; --j)
            for (int k = 1; k <= min(j - 1, cnt[v]); ++k) {
                d[u][j][0] = min(d[u][j][0], d[u][j - k][0] + d[v][k][0] + 2 * dis[v]);
                d[u][j][1] = min(d[u][j][1], d[u][j - k][0] + d[v][k][1] + dis[v]);
                d[u][j][1] = min(d[u][j][1], d[v][k][0] + 2 * dis[v] + d[u][j - k][1]);
            }
    }
}

int main() {
    while (~scanf("%d", &n) && n) {
        for (int i = 0; i < n; ++i) g[i].clear();
        for (int i = 1; i < n; ++i) {
            int u, v, t;
            scanf("%d%d%d", &v, &u, &t);
            g[u].push_back(v);
            dis[v] = t;
        }
        dp(0);
        scanf("%d", &q);
        printf("Case %d:\n", ++kase);
        for (int i = 0; i < q; ++i) {
            scanf("%d", &x);
            int ans;
            for (int j = n; j > 0; --j)
                if (d[0][j][1] <= x) {
                    ans = j;
                    break;
                }
            printf("%d\n", ans);
        }
    }
    return 0;
}