// UVa 1121
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 100000 + 5;
int n, s, a[maxn];

int main() {
    while (~scanf("%d%d", &n, &s)) {
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        int sum = 0, ans = n + 1;
        int l = 0, r = 0;
        while (r < n) {
            sum += a[r];
            if (sum >= s) {
                ans = min(ans, r - l + 1);
                while (l <= r && sum >= s) {
                    ans = min(ans, r - l + 1);
                    sum -= a[l++];
                }
            }
            r++;
        }
        printf("%d\n", ans == n + 1 ? 0 : ans);
    }
    return 0;
} 