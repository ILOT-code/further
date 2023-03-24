#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 75 + 5;
int T, n, a[maxn * 2][maxn * 2];
int sum[maxn * 2][maxn * 2], ret[maxn * 2];

int maxsub(int p) {
    int pre = 0, ans = -INF;
    for (int i = p; i < p + n; ++i) {
        ans = max(ans, pre + ret[i]);
        pre += ret[i];
        if (pre < 0) pre = 0;
    }
    return ans;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                scanf("%d", &a[i][j]);
                a[i][j + n] = a[i + n][j] = a[i + n][j + n] = a[i][j];
            }

        int len = 2 * n - 2;
        for (int i = 0; i <= len; ++i)
            for (int j = 0; j <= len; ++j) {
                if (i == 0)
                    sum[i][j] = a[i][j];
                else
                    sum[i][j] = sum[i - 1][j] + a[i][j];
            }

        int ans = -INF;
        for (int i = 0; i <= len; ++i)
            for (int j = i; j < i + n && j <= len; ++j) {
                for (int k = 0; k <= len; ++k) ret[k] = sum[j][k] - sum[i][k] + a[i][k];
                for (int k = 0; k < n; ++k) {
                    int tmp = maxsub(k);
                    ans = max(ans, tmp);
                }
            }
        printf("%d\n", ans);
    }
    return 0;
}