// UVa 1432
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 5000 + 5;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
const double PI = acos(-1);
int kase, n, k;

struct Point {
    double ang, r;
    Point(double x = 0, double y = 0) {
        ang = atan2(x, y);
        r = sqrt(x * x + y * y);
    }
    bool operator<(const Point& rhs) const { return ang < rhs.ang; }
} po[maxn * 2];
double rankr[maxn];
int que[2 * maxn], cnt;

int main() {
    while (~scanf("%d%d", &n, &k) && (n || k)) {
        for (int i = 0; i < n; ++i) {
            double x, y;
            scanf("%lf%lf", &x, &y);
            po[i] = Point(x, y);
            rankr[i] = po[i].r;
        }
        sort(rankr, rankr + n);
        sort(po, po + n);
        for (int i = n; i < 2 * n; ++i) po[i] = po[i - n], po[i].ang += 2 * PI;

        double ans = INF;
        for (int i = 0; i < n; ++i) {
            if (i != 0 && fabs(rankr[i] - rankr[i - 1]) < eps) continue;
            double r = rankr[i];
            cnt = 0;
            for (int j = 0; j < 2 * n; ++j)
                if (po[j].r < r + eps) que[cnt++] = j;

            int first = 0, tot = 0;
            for (int j = 0; j < cnt; ++j) {
                tot++;
                if (tot == 1) first = j;
                if (que[j] - que[first] >= n) break;
                if (tot == k) {
                    double angle = po[que[j]].ang - po[que[first]].ang;
                    double area = angle * r * r / 2.0;
                    ans = min(ans, area);
                    first++;
                    tot--;
                }
            }
        }
        if (k == 0) ans = 0;
        printf("Case #%d: %.2lf\n", ++kase, ans);
    }
    return 0;
}