#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;

const int maxn = 200000 + 5;
const LL INF = (1 << 62);
int M, cnt;
char op[2];
LL D, n, t, d[4 * maxn];

LL query(int l, int r, int s, int t, int p) {
    if (l <= s && t <= r) return d[p];
    int m = (s + t) >> 1;
    LL ans = -INF;
    if (l <= m) ans = query(l, r, s, m, 2 * p);
    if (r > m) ans = max(ans, query(l, r, m + 1, t, 2 * p + 1));
    return ans;
}
void add(int l, int v, int s, int t, int p) {
    if (s == t) {
        d[p] = v;
        return;
    }
    int m = (s + t) >> 1;
    if (l <= m) add(l, v, s, m, 2 * p);
    if (l > m) add(l, v, m + 1, t, 2 * p + 1);
    d[p] = max(d[2 * p], d[2 * p + 1]);
}

int main() {
    scanf("%d %lld", &M, &D);
    for (int i = 0; i < M; ++i) {
        scanf("%s %lld", op, &n);
        if (op[0] == 'A') {
            add(cnt + 1, (n + t) % D, 1, M, 1);
            cnt++;
        }
        if (op[0] == 'Q') {
            if (n == 0)
                t = 0;
            else
                t = query(cnt - n + 1, cnt, 1, M, 1) % D;
            printf("%lld\n", t);
        }
    }
    return 0;
}