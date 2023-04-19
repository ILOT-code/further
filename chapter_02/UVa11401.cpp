#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1000000 + 10;
long long f[maxn];

inline void init() {
    f[3] = 0;
    for (long long x = 4; x < maxn; ++x) {
        f[x] = f[x - 1];
        if (x % 2)
            f[x] += (x - 3) / 2 * (x - 1) / 2;
        else
            f[x] += (x - 2) / 2 * (x - 2) / 2;
    }
}
int main() {
    init();
    int n;
    while (~scanf("%d", &n)) {
        if (n < 3) break;
        printf("%lld\n", f[n]);
    }
    return 0;
}