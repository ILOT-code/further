// UVa 1398
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 100000 + 5;
const int INF = 0x3f3f3f3f;
const int lcm = 2520; // lcm(1~10) = 2520
int T, w, h, n;
struct Event {
    int t;
    bool flag;
    bool operator<(const Event& a) const { return t < a.t || (t == a.t && flag && !a.flag); }
} events[2 * maxn];
void update(int x, int v, int w, int& l, int& r) {
    if (v == 0 && (x <= 0 || x >= w)) r = l - 1;
    if (v > 0) {
        l = max(l, -x * lcm / v);
        r = min(r, (w - x) * lcm / v);
    }
    if (v < 0) {
        l = max(l, (w - x) * lcm / v);
        r = min(r, -x * lcm / v);
    }
}
int main() {
    scanf("%d", &T);
    while (T--) {
        int cnt = 0;
        scanf("%d%d%d", &w, &h, &n);
        for (int i = 0; i < n; ++i) {
            int x, y, a, b;
            scanf("%d%d%d%d", &x, &y, &a, &b);
            int l = 0, r = INF;
            update(x, a, w, l, r);
            update(y, b, h, l, r);
            if (r > l) {
                events[cnt++] = Event{l, 0};
                events[cnt++] = Event{r, 1};
            }
        }
        sort(events, events + cnt);
        int ans = 0, ret = 0;
        for (int i = 0; i < cnt; ++i) ret += events[i].flag ? -1 : 1, ans = max(ans, ret);
        printf("%d\n", ans);
    }
    return 0;
}