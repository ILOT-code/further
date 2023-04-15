// UVa 1228
// 在下面两条限制下，可能值总数不变：
// 1：序列中的1按顺序到达，0也是。
// 2：设P是原序列K的子序列（不必连续），P是已经接收到的位，那么P的最右边那位没有延迟。
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 64 + 1;
int kase, n, d, K[maxn], zcnt, ocnt, Z[maxn], O[maxn], laterz[maxn], latero[maxn];
unsigned long long k, f[maxn][maxn], maxv, minv;

bool crz(int i, int j) { return i < zcnt && Z[i + 1] + d >= O[j]; }
bool cro(int i, int j) { return j < ocnt && O[j + 1] + d >= Z[i]; }

void solve() {
    zcnt = ocnt = maxv = minv = 0;
    for (int i = 0; i < n; ++i) {
        if (K[i] == 1) {
            O[++ocnt] = i;
            maxv = 2 * maxv + 1;
            while (laterz[i]) maxv *= 2, laterz[i]--;
            latero[min(i + d, n - 1)]++;
            while (latero[i]) minv = 2 * minv + 1, latero[i]--;
        } else {
            Z[++zcnt] = i;
            minv *= 2;
            while (latero[i]) minv = 2 * minv + 1, latero[i]--;
            laterz[min(i + d, n - 1)]++;
            while (laterz[i]) maxv *= 2, laterz[i]--;
        }
    }

    memset(f, 0, sizeof(f));
    f[0][0] = 1;
    for (int i = 0; i <= zcnt; ++i)
        for (int j = 0; j <= ocnt; ++j)
            if (f[i][j]) {
                if (crz(i, j)) f[i + 1][j] += f[i][j];
                if (cro(i, j)) f[i][j + 1] += f[i][j];
            }
    printf("Case %d: %llu %llu %llu\n", ++kase, f[zcnt][ocnt], minv, maxv);
}

int main() {
    while (~scanf("%d%d%llu", &n, &d, &k) && n) {
        for (int i = 0; i < n; ++i) {
            K[n - 1 - i] = k % 2;
            k = k / 2;
        }
        solve();
    }
    return 0;
}