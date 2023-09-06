// UVa 12105
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxd = 50 + 5;
const int maxm = 3000 + 5;
const int c[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int kase, n, M;
int d[maxd][maxm];
int ans[maxd], reminder[maxd];
void init() {
    reminder[0] = 1;
    for (int i = 1; i <= n / 2; ++i) reminder[i] = (10 * reminder[i - 1]) % M;
    memset(d, INF, sizeof(d));
    d[0][0] = 0;
}

int main() {
    while (~scanf("%d%d", &n, &M) && n) {
        init();
        for (int i = 0; i < (n / 2); ++i)
            for (int j = 0; j < M; ++j)
                if (d[i][j] != INF)
                    for (int k = 0; k < 10; ++k)
                        if (d[i][j] + c[k] <= n) {
                            int t = (10 * j + k) % M;
                            d[i + 1][t] = min(d[i + 1][t], c[k] + d[i][j]);
                        }

        int p = n / 2, res = 0;
        for (; p >= 0; --p)
            if (d[p][0] != INF) break;

        int fi = p;
        while (p)
            for (int k = 9; k >= 0; --k) {
                int newres = (res - (k * reminder[p - 1]) % M + M) % M;
                if (d[p - 1][newres] + c[k] <= n) {
                    n -= c[k];
                    ans[p] = k, p--, res = newres;
                    break;
                }
            }

        printf("Case %d: ", ++kase);
        if (fi == 0)
            printf("-1");
        else if (ans[fi] == 0)
            printf("0");
        else
            for (int i = fi; i > 0; --i) printf("%d", ans[i]);
        printf("\n");
    }
    return 0;
}