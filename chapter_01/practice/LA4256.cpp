// UVa 1424
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 300 + 5;
int T, n, M, len, p[maxn], d[maxn][maxn];
bool link[maxn][maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        memset(link, 0, sizeof(link));
        scanf("%d%d", &n, &M);
        for (int i = 0, u, v; i < M; ++i) {
            scanf("%d%d", &u, &v);
            link[u][v] = link[v][u] = 1;
        }
        scanf("%d", &len);
        for (int i = 1; i <= len; ++i) scanf("%d", &p[i]);

        for (int i = 1; i <= len; ++i)
            for (int j = 1; j <= n; ++j) d[i][j] = INF;
        for (int i = 1; i <= n; ++i) d[0][i] = 0;

        for (int i = 1; i <= len; ++i)
            for (int j = 1; j <= n; ++j) {
                for (int k = 1; k <= n; ++k)
                    if (k == j || link[j][k]) d[i][j] = min(d[i][j], d[i - 1][k]);
                if (j != p[i]) d[i][j]++;
            }

        int ans = INF;
        for (int i = 1; i <= n; ++i) ans = min(ans, d[len][i]);
        printf("%d\n", ans);
    }
    return 0;
}