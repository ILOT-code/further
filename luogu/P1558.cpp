#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 100000 + 5;
const int maxt = 30 + 2;
int n, t, q;
int a[maxn];
int d[4 * maxn], b[4 * maxn];

void build(int s, int t, int p) {
    d[p] = 1, b[p] = -1;
    if (s == t) return;
    int m = (s + t) >> 1;
    build(s, m, 2 * p), build(m + 1, t, 2 * p + 1);
}
void pushdown(int s, int t, int p) {
    if (s == t || b[p] == -1) return;
    b[2 * p] = b[2 * p + 1] = b[p];
    d[2 * p] = d[2 * p + 1] = (1 << b[p]);
    b[p] = -1;
}
void caozuo(int l, int r, int v, int s, int t, int p) {
    if (l <= s && t <= r) {
        b[p] = v, d[p] = (1 << v);
        return;
    }
    int m = (s + t) >> 1;
    pushdown(s, t, p);
    if (l <= m) caozuo(l, r, v, s, m, 2 * p);
    if (r > m) caozuo(l, r, v, m + 1, t, 2 * p + 1);
    d[p] = d[2 * p] | d[2 * p + 1];
}
int query(int l, int r, int s, int t, int p) {
    if (l <= s && t <= r) return d[p];
    int m = (s + t) >> 1;
    pushdown(s, t, p);

    int ans = 0;
    if (l <= m) ans |= query(l, r, s, m, 2 * p);
    if (r > m) ans |= query(l, r, m + 1, t, 2 * p + 1);
    return ans;
}
int count(int s) {
    int ans = 0;
    while (s) ans += s & 1, s >>= 1;
    return ans;
}

int main() {
    scanf("%d%d%d", &n, &t, &q);
    build(1, n, 1);
    int l, r, c;
    char op[2];
    for (int i = 0; i < q; ++i) {
        scanf("%s", op);
        if (op[0] == 'C') {
            scanf("%d%d%d", &l, &r, &c);
            if (l > r) swap(l, r);
            caozuo(l, r, c - 1, 1, n, 1);
        }
        if (op[0] == 'P') {
            scanf("%d%d", &l, &r);
            if (l > r) swap(l, r);
            printf("%d\n", count(query(l, r, 1, n, 1)));
        }
    }
    return 0;
}