// UVa 1335
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 100000 + 5;
int n, a[maxn], left[maxn], right[maxn];
bool test(int p) {
    int x = a[1], y = p - a[1];
    left[1] = x, right[1] = 0;
    for (int i = 2; i <= n; ++i) {
        if (i % 2 == 1) {
            right[i] = min(y - right[i - 1], a[i]);
            left[i] = a[i] - right[i];
            if (left[i] + left[i - 1] > x) return false;
        } else {
            left[i] = min(x - left[i - 1], a[i]);
            right[i] = a[i] - left[i];
            if (right[i] + right[i - 1] > y) return false;
        }
    }
    return left[n] == 0;
}

int main() {
    while (~scanf("%d", &n) && n) {
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        a[n + 1] = a[1];
        int l = 0, r = 0;
        for (int i = 1; i <= n; ++i) l = max(l, a[i] + a[i + 1]), r = max(r, a[i] * 3);
        if (n % 2 == 1) {
            while (l < r) {
                int m = (l + r) / 2;
                if (test(m)) r = m;
                else l = m + 1;
            }
        }
        printf("%d\n", n == 1 ? a[1] : l);
    }
    return 0;
}