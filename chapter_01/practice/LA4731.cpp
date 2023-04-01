// UVa 1456
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 100 + 5;
const int INF = 0x3f3f3f3f;
int T, n, w, sum, u[maxn], pre[maxn];
double d[maxn][maxn];

bool cmp(int x, int y) { return x > y; }
int main() {
    scanf("%d", &T);
    for (int i = 1; i < maxn; ++i) d[i][0] = INF;
    while (T--) {
        scanf("%d%d", &n, &w);
        for (int i = 1; i <= n; ++i) scanf("%d", &u[i]);
        sort(u + 1, u + 1 + n, cmp);
        sum = 0;
        for (int i = 1; i <= n; ++i) {
            pre[i] = pre[i - 1] + u[i];
            sum += u[i];
        }

        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= min(i, w); ++j) {
                d[i][j] = INF;
                for (int k = j - 1; k < i; ++k) d[i][j] = min(d[i][j], d[k][j - 1] + (pre[i] - pre[k]) / (sum * 1.0) * i);
            }
        printf("%.4lf\n", d[n][w]);
    }
    return 0;
}