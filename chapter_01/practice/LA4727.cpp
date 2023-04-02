// UVa 1452
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int T, n, k;
// 复杂度是klogn，但此题k很大，采用这个算法会更慢。
int josephus(int n, int k, int d) {
    if (n == d) return (k - 1) % d;
    if (k == 1) return n - d;
    if (k > n || (n - n / k < d)) return (josephus(n - 1, k, d) + k) % n; // 线性算法
    int res = josephus(n - n / k, k, d);
    res -= n % k;
    if (res < 0)
        res += n;
    else
        res += res / (k - 1);
    return res;
}
// 线性复杂度
void solve() {
    int res0 = 0, res1 = (k - 1) % 2, res2 = (k - 1) % 3;
    for (int i = 2; i <= n; ++i) res0 = (res0 + k) % i;
    for (int i = 3; i <= n; ++i) res1 = (res1 + k) % i;
    for (int i = 4; i <= n; ++i) res2 = (res2 + k) % i;
    printf("%d %d %d\n", res2 + 1, res1 + 1, res0 + 1);
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &k);
        solve();
    }
    return 0;
}