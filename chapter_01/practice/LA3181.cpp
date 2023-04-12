// UVa 1336
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1000 + 5;
const double INF = 1e20;
int n, xsta, sumd[maxn], sumc;
double v, f[maxn][maxn][2];
bool vis[maxn][maxn][2];
struct Point {
    int x, c, d;
    bool operator<(const Point& rhs) { return x < rhs.x; }
} po[maxn];

double cost(int i, int j, int x1, int x2) {
    double t = fabs(x2 - x1) / v;
    double cur = sumd[n] - (sumd[j] - sumd[i] + po[i].d);
    return t * cur;
}
double dp(int l, int r, int pos) {
    if (vis[l][r][pos]) return f[l][r][pos];
    vis[l][r][pos] = 1;
    double& ans = f[l][r][pos];
    if (l == 0 && r == n) return ans = 0.0;

    ans = INF;
    int x = pos ? po[r].x : po[l].x;
    if (l > 0) ans = min(ans, dp(l - 1, r, 0) + cost(l, r, x, po[l - 1].x));
    if (r < n) ans = min(ans, dp(l, r + 1, 1) + cost(l, r, x, po[r + 1].x));
    return ans;
}

int main() {
    while (~scanf("%d%lf%d", &n, &v, &xsta) && n) {
        int p = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d", &po[i].x, &po[i].c, &po[i].d);
            if (po[i].x < xsta) p++;
        }
        po[n] = Point{xsta, 0, 0};
        sort(po, po + n + 1);

        sumd[0] = po[0].d, sumc = po[0].c;
        for (int i = 1; i <= n; ++i) sumd[i] = po[i].d + sumd[i - 1], sumc += po[i].c;

        memset(vis, 0, sizeof(vis));
        printf("%d\n", (int)dp(p, p, 0) + sumc);
    }
    return 0;
}