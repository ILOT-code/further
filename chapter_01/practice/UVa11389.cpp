#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 100 + 5;
int n, d, r, a[maxn], b[maxn];
int main() {
    while (~scanf("%d%d%d", &n, &d, &r) && n) {
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
        sort(a, a + n);
        sort(b, b + n);
        int ans = 0;
        for (int i = 0; i < n; ++i) ans += max(0, a[i] + b[n - 1 - i] - d);
        printf("%d\n", ans * r);
    }
    return 0;
}