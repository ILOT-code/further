// UVa 1325
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1000 + 5;
int n, cnt;

struct Point {
    double x, y, z;
    int flag, same, diff;
} p[maxn];
struct Dist {
    int l, r;
    double dis;
    bool operator<(const Dist& rhs) const { return dis < rhs.dis; }
} d[maxn * maxn];

void solve() {
    int ans = 0, tmp = 0;
    double R = 0;
    for (int i = 0; i < cnt; ++i) {
        int l = d[i].l, r = d[i].r;
        if (p[l].flag == p[r].flag) {
            p[l].same++, p[r].same++;
            if (p[l].same == p[l].diff) tmp--;
            if (p[r].same == p[r].diff) tmp--;
        } else {
            p[l].diff++, p[r].diff++;
            if (p[l].diff == p[l].same + 1) tmp++;
            if (p[r].diff == p[r].same + 1) tmp++;
        }
        if (i != cnt - 1 && fabs(d[i].dis - d[i + 1].dis) < 1e-6) continue;
        if (tmp > ans) ans = tmp, R = d[i].dis;
    }
    printf("%d\n%.4lf\n", ans, R);
}

int main() {
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) {
            scanf("%lf%lf%lf%d", &p[i].x, &p[i].y, &p[i].z, &p[i].flag);
            p[i].same = 1, p[i].diff = 0;
        }
        cnt = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j) {
                d[cnt].l = i, d[cnt].r = j;
                d[cnt++].dis = sqrt((p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y) + (p[i].z - p[j].z) * (p[i].z - p[j].z));
            }
        sort(d, d + cnt);
        solve();
    }
    return 0;
}