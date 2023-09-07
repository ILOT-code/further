#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;

const int maxm = 100000 + 5;
const int maxn = 30000 + 10;
int n, m, a[maxm], f[maxn];
int d[4 * maxm], b[4 * maxm];
int left[maxn], right[maxn];

void build(int s, int t, int p) {
    b[p] = 0;
    if (s == t) {
        d[p] = a[s];
        return;
    }
    int m = (s + t) >> 1;
    build(s, m, 2 * p), build(m + 1, t, 2 * p + 1);
    d[p] = d[2 * p] + d[2 * p + 1];
}
void pushdowm(int s, int t, int p) {
    if (s == t || b[p] == 0) return;
    int m = (s + t) >> 1;
    d[2 * p] += (m - s + 1) * b[p], d[2 * p + 1] += (t - m) * b[p];
    b[2 * p] += b[p], b[2 * p + 1] += b[p];
    b[p] = 0;
}
int getsum(int l, int r, int s, int t, int p) {
    if (l <= s && t <= r) return d[p];
    int m = (s + t) >> 1;
    pushdowm(s, t, p);
    int ans = 0;
    if (l <= m) ans += getsum(l, r, s, m, 2 * p);
    if (r > m) ans += getsum(l, r, m + 1, t, 2 * p + 1);
    return ans;
}
void add(int l, int r, int v, int s, int t, int p) {
    if (l <= s && t <= r) {
        b[p] += v, d[p] += (t - s + 1) * v;
        return;
    }
    int m = (s + t) >> 1;
    pushdowm(s, t, p);
    if (l <= m) add(l, r, v, s, m, 2 * p);
    if (r > m) add(l, r, v, m + 1, t, 2 * p + 1);
    d[p] = d[2 * p] + d[2 * p + 1];
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &f[i]);
        m = max(m, f[i]);
        a[f[i]]++;
    }
    m += 1;

    build(0, m, 1);
    for (int i = n - 1; i >= 0; --i) {
        add(f[i], f[i], -1, 0, m, 1);
        left[i] = getsum(0, f[i] - 1, 0, m, 1);
    }

    build(0, m, 1);
    for (int i = 0; i < n; ++i) {
        add(f[i], f[i], -1, 0, m, 1);
        right[i] = getsum(f[i] + 1, m, 0, m, 1);
    }

    LL ans = 0;
    for (int i = 0; i < n; ++i) ans += 1ll * right[i] * left[i];
    printf("%lld\n", ans);
    return 0;
}