// UVa 1421
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 5000 + 5;
const double eps = 1e-6;
int T, n;
double w;
struct Goal {
    double d, l, r;
    bool operator<(const Goal& rhs) const { return d < rhs.d; }
} a[maxn];

int judge(double x) {
    double r1 = atan2(a[0].d, a[0].l - x), l1 = atan2(a[0].d, a[0].r - x);
    for (int i = 1; i < n; ++i) {
        double r2 = atan2(a[i].d, a[i].l - x), l2 = atan2(a[i].d, a[i].r - x);
        if (l2 - r1 > eps) return -1; // right
        if (l1 - r2 > eps) return 1;  // left
        r1 = min(r1, r2), l1 = max(l1, l2);
    }
    return 0;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%lf%d", &w, &n);
        for (int i = 0; i < n; ++i) scanf("%lf%lf%lf", &a[i].d, &a[i].l, &a[i].r);
        sort(a, a + n);
        bool flag = false;
        double l = 0, r = w;
        while (r - l > eps) {
            double mid = (l + r) / 2;
            int k = judge(mid);
            if (k == 0) {
                flag = true;
                break;
            }
            if (k == -1) l = mid;
            if (k == 1) r = mid;
        }
        printf("%s\n", flag ? "YES" : "NO");
    }
    return 0;
}