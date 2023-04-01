#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 16;
int T, kase, n;
int have[1 << maxn], kill[1 << maxn];
long long d[1 << maxn];

int get() {
    int res = 0;
    for (int i = 0, t; i < n; ++i) {
        scanf("%1d", &t);
        if (t) res |= 1 << i;
    }
    return res;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i <= n; ++i) have[i] = get();
        int total = (1 << n) - 1;
        for (int s = 0; s <= total; ++s) {
            kill[s] = have[0];
            for (int i = 0; i < n; ++i)
                if (s & (1 << i)) kill[s] |= have[i + 1];
        }

        memset(d, 0, sizeof(d));
        d[0] = 1;
        for (int s = 1; s <= total; ++s)
            for (int i = 0; i < n; ++i)
                if (s & (1 << i))
                    if (kill[s ^ (1 << i)] & (1 << i)) d[s] += d[s ^ (1 << i)];

        printf("Case %d: %lld\n", ++kase, d[total]);
    }
    return 0;
}