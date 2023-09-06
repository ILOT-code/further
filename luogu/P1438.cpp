#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;

const int maxn = 100000 + 5;
int n, q, a[maxn];
LL d[4 * maxn], b[4 * maxn];

void build(int s, int t, int p) {
    if (s == t) {
        d[p] = a[s];
        return;
    }
    int m = (s + t) >> 1;
    build(s, m, 2 * p), build(m + 1, t, 2 * p + 1);
    d[p] = d[2 * p] + d[2 * p + 1];
}
void pushdown(int s, int t, int p) {
    if (s == t || b[p] == 0) return;
    int m = (s + t) >> 1;
    b[2 * p] += b[p], b[2 * p + 1] += b[p];
    d[2 * p] += 1ll * (m - s + 1) * b[p], d[2 * p + 1] += 1ll * (t - m) * b[p];
    b[p] = 0;
}
LL getsum(int l, int r, int s, int t, int p) {
    if (l <= s && t <= r) return d[p];
    int m = (s + t) >> 1;
    pushdown(s, t, p);
    int ans = 0;
    if (l <= m) ans += getsum(l, r, s, m, 2 * p);
    if (r > m) ans += getsum(l, r, m + 1, t, 2 * p + 1);
    return ans;
}
void add(int l, int r, LL v, int s, int t, int p) {
    if (l <= s && t <= r) {
        b[p] += v, d[p] += 1ll * (t - s + 1) * v;
        return;
    }
    int m = (s + t) >> 1;
    pushdown(s, t, p);
    if (l <= m) add(l, r, v, s, m, 2 * p);
    if (r > m) add(l, r, v, m + 1, t, 2 * p + 1);
    d[p] = d[2 * p] + d[2 * p + 1];
}

int main() {
    scanf("%d%d", &n, &q);
    int pre = 0, t;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &t);
        a[i] = t - pre, pre = t;
    }
    build(1, n, 1);
    int op, l, r, k, m;
    int cnt = 0;
    for (int i = 0; i < q; ++i) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d%d%d%d", &l, &r, &k, &m);
            add(l, r, m, 1, n, 1);
            add(l, l, k - m, 1, n, 1);
            if (r + 1 <= n) add(r + 1, r + 1, -(k + 1ll * (r - l) * m), 1, n, 1);
        }
        if (op == 2) {
            scanf("%d", &l);
            printf("%lld\n", getsum(1, l, 1, n, 1));
        }
    }
    return 0;
}