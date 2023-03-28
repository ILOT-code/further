// UVa 1481
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 3000 + 5;
int n, a[maxn], b[maxn];
int main() {
    while (~scanf("%d", &n) && n) {
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        for (int i = 0, t; i < n; ++i) {
            scanf("%d", &t);
            b[t] = i;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int l = b[a[i]], r = b[a[i]];
            for (int j = i + 1; j < n; ++j) {
                int p = b[a[j]];
                l = min(l, p);
                r = max(r, p);
                if (r - l == j - i) ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}