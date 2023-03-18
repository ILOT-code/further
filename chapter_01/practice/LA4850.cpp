// UVa 1467
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 500 + 5;
int T, n;
struct Point {
    int s, d;
    bool operator<(const Point& rhs) const { return d < rhs.d || (d == rhs.d && s < rhs.s); }
} po[maxn];

void pushup(int now, int id, int& t1, int& p1, int& t2, int& p2) {
    if (now >= t1) {
        t2 = t1, p2 = p1;
        t1 = now, p1 = id;
    } else if (now >= t2) {
        t2 = now, p2 = id;
    }
}
int solve(int p, int p2) {
    int time = 0, t1 = 0, t2 = 0, id1 = 0, id2 = 0;
    for (int i = 0; i <= p2; ++i) {
        if (i == p) continue;
        time += po[i].s;
        pushup(max(time - po[i].d, 0), i, t1, id1, t2, id2);
    }
    time += po[p].s;
    pushup(max(time - po[p].d, 0), p, t1, id1, t2, id2);
    return t1 + t2;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d%d", &po[i].s, &po[i].d);
        sort(po, po + n);

        int time = 0, t1 = 0, t2 = 0, p1 = 0, p2 = 0;
        for (int i = 0; i < n; ++i) {
            time += po[i].s;
            pushup(max(time - po[i].d, 0), i, t1, p1, t2, p2);
        }
        int ans = t1 + t2;
        if (p1 > p2) swap(p1, p2);
        for (int i = 0; i <= p1; ++i) ans = min(ans, solve(i, p2));
        printf("%d\n", ans);
    }
    return 0;
}