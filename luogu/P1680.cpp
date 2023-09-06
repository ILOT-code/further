#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;

const int mod = 1e9 + 7;
int n, M;

LL Qpow(LL a, LL b, LL p) {
    LL ans = 1;
    while (b) {
        if (b & 1) ans = (ans * a) % p;
        a = (a * a) % p;
        b >>= 1;
    }
    return ans;
}

LL C(LL n, LL m, LL p) {
    if (n < m) return 0;
    if (m > n - m) m = n - m;
    LL s1 = 1, s2 = 1;
    for (int i = 0; i < m; ++i) {
        s1 = s1 * (n - i) % p;
        s2 = s2 * (i + 1) % p;
    }
    return s1 * Qpow(s2, p - 2, p) % p;
}

LL Lucas(LL n, LL m, LL p) {
    if (m == 0) return 1;
    return C(n % p, m % p, p) * Lucas(n / p, m / p, p) % p;
}

int main() {
    scanf("%d%d", &n, &M);
    for (int i = 0, t; i < M; ++i) {
        scanf("%d", &t);
        n -= t;
    }
    printf("%d\n", Lucas(n - 1, M - 1, mod));
    return 0;
}