// UVa 11549
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;

int T, n, k;
int buf[20];
int pren(int x) {
    LL t = 1LL * x * x;
    int p = 0;
    while (t) {
        buf[p++] = t % 10;
        t /= 10;
    }
    int end = (p > n) ? (p - n) : 0;
    int ret = 0;
    for (int i = p - 1; i >= end; --i) ret = ret * 10 + buf[i];
    return ret;
}
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &k);
        int ans = k;
        int k1 = k, k2 = k;
        do {
            k1 = pren(k1);
            k2 = pren(k2), ans = max(k2, ans);
            k2 = pren(k2), ans = max(k2, ans);
        } while (k1 != k2);
        printf("%d\n", ans);
    }
    return 0;
}
