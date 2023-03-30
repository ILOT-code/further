#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1000 + 5;
const int INF = 0x3f3f3f3f;
int T, k;
int d[maxn][30], have[maxn][30], cnt[maxn];
char s[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%s", &k, s);
        memset(have, 0, sizeof(have));
        memset(cnt, 0, sizeof(cnt));

        int m = strlen(s) / k;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < k; ++j) {
                int t = s[i * k + j] - 'a';
                if (have[i][t] == 0) cnt[i]++;
                have[i][t]++;
            }

        memset(d, INF, sizeof(d));
        for (int i = 0; i < 26; ++i)
            if (have[0][i]) d[0][i] = cnt[0];
        for (int i = 1; i < m; ++i)
            for (int j = 0; j < 26; ++j)
                if (have[i][j]) {
                    for (int t = 0; t < 26; ++t)
                        if (have[i - 1][t]) {
                            if (have[i][t] && (j != t || cnt[i] == 1))
                                d[i][j] = min(d[i][j], d[i - 1][t] + cnt[i] - 1);
                            else
                                d[i][j] = min(d[i][j], d[i - 1][t] + cnt[i]);
                        }
                }

        int ans = INF;
        for (int i = 0; i < 26; ++i)
            if (have[m - 1][i]) ans = min(ans, d[m - 1][i]);

        printf("%d\n", ans);
    }
    return 0;
}