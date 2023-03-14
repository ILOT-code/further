#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 100000 + 10;
const int maxm = 1000000 + 10;
const double eps = 1e-9;

struct Node {
    double x, y;
} gate[maxn];

int T, n, s, shoes[maxm];
double w, vh;

int check(int v) {
    double l = gate[1].x, r = gate[1].x + w;
    for (int i = 2; i <= n; ++i) {
        double d = vh * (gate[i].y - gate[i - 1].y) / (double)v;
        l -= d, r += d;
        l = max(l, gate[i].x);
        r = min(r, gate[i].x + w);
        if (l - r >= eps) return false;
    }
    return true;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%lf%lf%d", &w, &vh, &n);
        for (int i = 1; i <= n; ++i) scanf("%lf%lf", &gate[i].x, &gate[i].y);
        scanf("%d", &s);
        for (int i = 1; i <= s; ++i) scanf("%d", &shoes[i]);
        sort(shoes + 1, shoes + s + 1);
        int l = 1, r = s + 1;

        while (l < r) {
            int m = (l + r) / 2;
            if (check(shoes[m])) l = m + 1;
            else r = m;
        }

        if (l == 1) printf("IMPOSSIBLE\n");
        else printf("%d\n", l - 1);
    }
    return 0;
}