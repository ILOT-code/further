#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 40 + 5;
const int maxm = 400;
int n, s, a[maxn][maxn];
long long d[maxn][maxn][maxm];

void print_ans(int x, int y, int sum) {
    if (x == 2 * n - 1) return;
    int nesum = sum - a[x][y];
    bool flag = x < n;
    if (d[x + 1][y - flag][nesum]) {
        printf("L");
        print_ans(x + 1, y - flag, nesum);
    } else {
        printf("R");
        print_ans(x + 1, y + !flag, nesum);
    }
}

int main() {
    while (scanf("%d%d", &n, &s) && (n || s)) {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n + 1 - i; ++j) scanf("%d", &a[i][j]);
        for (int i = n + 1; i <= 2 * n - 1; ++i)
            for (int j = 1; j <= i - n + 1; ++j) scanf("%d", &a[i][j]);

        memset(d, 0, sizeof(d));
        for (int i = 1; i <= n; ++i) d[2 * n - 1][i][a[2 * n - 1][i]] = 1;
        for (int i = 2 * n - 2; i >= n; --i)
            for (int j = 1; j <= i - n + 1; ++j)
                for (int k = a[i][j]; k <= s; ++k) d[i][j][k] = d[i + 1][j][k - a[i][j]] + d[i + 1][j + 1][k - a[i][j]];

        for (int i = n - 1; i >= 1; --i)
            for (int j = 1; j <= n + 1 - i; ++j)
                for (int k = a[i][j]; k <= s; ++k) d[i][j][k] = d[i + 1][j - 1][k - a[i][j]] + d[i + 1][j][k - a[i][j]];

        long long ans = 0;
        for (int i = 1; i <= n; ++i) ans += d[1][i][s];
        printf("%lld\n", ans);
        for (int i = 1; i <= n; ++i) {
            if (d[1][i][s] == 0) continue;
            printf("%d ", i - 1);
            print_ans(1, i, s);
            break;
        }
        printf("\n");
    }
    return 0;
}