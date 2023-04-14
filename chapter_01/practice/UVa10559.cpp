#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 200 + 5;
int T, kase, n, a[maxn], pre[maxn];
int f[maxn][maxn][maxn], vis[maxn][maxn][maxn];

int dp(int l, int r, int k) {
    if (vis[l][r][k]) return f[l][r][k];
    vis[l][r][k] = 1;
    int& ans = f[l][r][k];

    if (pre[r] > l)
        ans = dp(l, pre[r] - 1, 0) + (k + r - pre[r] + 1) * (k + r - pre[r] + 1);
    else
        ans = (r - l + 1 + k) * (r - l + 1 + k);

    for (int i = l; i < pre[r] - 1; ++i)
        if (a[i] == a[r] && a[i] != a[i + 1]) ans = max(ans, dp(i + 1, pre[r] - 1, 0) + dp(l, i, r - pre[r] + 1 + k));

    return ans;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        int pos = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i] != a[i - 1])
                pre[i] = pos = i;
            else
                pre[i] = pos;
        }
        memset(vis, 0, sizeof(vis));
        printf("Case %d: %d\n", ++kase, dp(1, n, 0));
    }
    return 0;
}