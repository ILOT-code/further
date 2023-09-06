#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;

const int maxn = 1000000 + 5;
const LL INF = 0x3f3f3f3f3f3f3f3f;
int n, q, a[maxn];
LL d[4 * maxn], b[4 * maxn], v[4 * maxn];

void build(int s, int t, int p) {
    if (s == t)
        d[p] = a[s];
    else {
        int m = (s + t) >> 1;
        build(s, m, 2 * p), build(m + 1, t, 2 * p + 1);
        d[p] = max(d[2 * p], d[2 * p + 1]);
    }
}
void pushdown(int s, int t, int p) {
    if (s == t) return;
    int m = (s + t) >> 1;
    if (v[p] != INF) {
        v[2 * p] = v[2 * p + 1] = v[p];
        b[2 * p] = b[2 * p + 1] = b[p];
        d[2 * p] = d[2 * p + 1] = v[p] + b[p];
        b[p] = 0, v[p] = INF;
    } else {
        b[2 * p] += b[p], b[2 * p + 1] += b[p];
        d[2 * p] += b[p], d[2 * p + 1] += b[p];
        b[p] = 0;
    }
}
LL getmax(int l, int r, int s, int t, int p) {
    if (l <= s && t <= r) return d[p];
    int m = (s + t) >> 1;
    pushdown(s, t, p);
    LL ans = -INF;
    if (l <= m) ans = max(getmax(l, r, s, m, 2 * p), ans);
    if (r > m) ans = max(getmax(l, r, m + 1, t, 2 * p + 1), ans);
    return ans;
}
void update(int l, int r, int va, int s, int t, int p) {
    if (l <= s && t <= r) {
        b[p] = 0, v[p] = va, d[p] = va;
        return;
    }
    int m = (s + t) >> 1;
    pushdown(s, t, p);
    if (l <= m) update(l, r, va, s, m, 2 * p);
    if (r > m) update(l, r, va, m + 1, t, 2 * p + 1);
    d[p] = max(d[2 * p], d[2 * p + 1]);
}
void add(int l, int r, int va, int s, int t, int p) {
    if (l <= s && t <= r) {
        b[p] += va, d[p] += va;
        return;
    }
    int m = (s + t) >> 1;
    pushdown(s, t, p);
    if (l <= m) add(l, r, va, s, m, 2 * p);
    if (r > m) add(l, r, va, m + 1, t, 2 * p + 1);
    d[p] = max(d[2 * p], d[2 * p + 1]);
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    memset(v, 0x3f, sizeof(v));
    build(1, n, 1);
    int op, l, r, x;
    while (q--) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d%d%d", &l, &r, &x);
            update(l, r, x, 1, n, 1);
        }
        if (op == 2) {
            scanf("%d%d%d", &l, &r, &x);
            add(l, r, x, 1, n, 1);
        }
        if (op == 3) {
            scanf("%d%d", &l, &r);
            printf("%lld\n", getmax(l, r, 1, n, 1));
        }
    }
    return 0;
}