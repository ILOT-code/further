// UVa 1382
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define fi first
#define se second
#define PII pair<int, int>
const int maxn = 100 + 5;
int kase, n, M, y[maxn], on[maxn], on2[maxn], left[maxn];
PII po[maxn];

int solve() {
    sort(po, po + n);
    sort(y, y + n);
    M = unique(y, y + n) - y;
    if (M <= 2) return n;

    int ans = 0;
    for (int a = 0; a < M; ++a)
        for (int b = a + 1; b < M; ++b) {
            int cnt = 0, last = -1;
            for (int i = 0; i < n; ++i) {
                if (po[i].se < y[a] || po[i].se > y[b]) continue;
                if (last == -1 || po[last].fi != po[i].fi) {
                    cnt++;
                    on[cnt] = on2[cnt] = 0;
                    left[cnt] = last == -1 ? 0 : left[cnt - 1] + on2[cnt - 1] - on[cnt - 1];
                    last = i;
                }
                if (po[i].se > y[a] && po[i].se < y[b]) on[cnt]++;
                if (po[i].se >= y[a] && po[i].se <= y[b]) on2[cnt]++;
            }
            int M = 0;
            for (int j = 1; j <= cnt; ++j) {
                ans = max(ans, left[j] + on2[j] + M);
                M = max(M, on[j] - left[j]);
            }
        }
    return ans;
}
int main() {
    while (~scanf("%d", &n) && n) {
        for (int i = 0; i < n; ++i) scanf("%d%d", &po[i].fi, &po[i].se), y[i] = po[i].se;
        printf("Case %d: %d\n", ++kase, solve());
    }
    return 0;
}