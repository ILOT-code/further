#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int mod = 1000007;
const int maxn = 20 + 1;
const int maxk = 500 + 5;
int T, kase, m, n, k, c[maxn * maxn][maxk];

inline void init() {
    c[0][0] = 1;
    for (int i = 1; i <= 400; ++i) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; ++j) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
    }
}

int slove() {
    int res = 0;
    for (int s = 0; s < 16; ++s) {
        int b = 0, a[4] = {0, 0, 0, 0};
        for (int i = 0; i < 4; ++i)
            if (s & (1 << i)) b++, a[i]++;

        int row = n - a[0] - a[1], col = m - a[2] - a[3];
        if (b % 2)
            res = (res + mod - c[row * col][k]) % mod;
        else
            res = (res + c[row * col][k]) % mod;
    }
    return res;
}

int main() {
    init();
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &n, &m, &k);
        printf("Case %d: %d\n", ++kase, slove());
    }
    return 0;
}