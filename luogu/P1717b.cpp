#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 25 + 5;
const int maxt = 20 * 12;
int n, h, t[maxn], ans;
struct Point {
    int f, d;
    bool operator<(const Point& rhs) const { return f < rhs.f; }
} p[maxn];
priority_queue<Point, vector<Point>> q;

int main() {
    scanf("%d%d", &n, &h);
    h *= 12;
    for (int i = 1; i <= n; ++i) scanf("%d", &p[i].f);
    for (int i = 1; i <= n; ++i) scanf("%d", &p[i].d);
    for (int i = 1; i < n; ++i) scanf("%d", &t[i]);

    int sumt = 0;
    for (int i = 1; i <= n; ++i) {
        sumt += t[i - 1];
        int nowt = h - sumt, ret = 0;
        if (nowt <= 0) break;
        while (!q.empty()) q.pop();
        q.push(Point{0, 0});
        for (int j = 1; j <= i; ++j) q.push(p[j]);

        while (nowt--) {
            Point u = q.top();
            q.pop();
            ret += u.f;
            u.f -= u.d, q.push(u);
        }
        ans = max(ans, ret);
    }

    printf("%d\n", ans);
    return 0;
}