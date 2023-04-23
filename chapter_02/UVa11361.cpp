#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 10 + 2;
int T, a, b, k, powc[maxn];
int d[maxn][100][100];

int dp(int n, int k1, int k2) {
    int& ans = d[n][k1][k2];
    if (ans != -1) return ans;
    if (n == 0) return ans = (k1 == 0 && k2 == 0);

    ans = 0;
    for (int i = 0; i < 10; ++i) {
        int nk1 = (k1 - i % k + k) % k;
        int nk2 = (k2 - (i * powc[n - 1]) % k + k) % k;
        ans += dp(n - 1, nk1, nk2);
    }
    return ans;
}

int f(int x) {
    int tmp[maxn], len = 0, t = x;
    while (t) tmp[len++] = t % 10, t /= 10;

    int k1 = 0, k2 = 0, ans = 0;
    for (int i = len - 1; i >= 0; --i) {
        for (int j = 0; j < tmp[i]; ++j) {
            int nk1 = (k1 - j % k + k) % k;
            int nk2 = (k2 - (j * powc[i]) % k + k) % k;
            ans += dp(i, nk1, nk2);
        }
        k1 = (k1 - tmp[i] % k + k) % k;
        k2 = (k2 - (tmp[i] * powc[i]) % k + k) % k;
    }
    ans += dp(0, k1, k2);
    return ans;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &a, &b, &k);
        powc[0] = 1 % k;
        for (int i = 1; i < maxn; ++i) powc[i] = (10 * powc[i - 1]) % k;
        memset(d, -1, sizeof(d));
        if (k >= 100)
            printf("0\n");
        else
            printf("%d\n", f(b) - f(a - 1));
    }
    return 0;
}