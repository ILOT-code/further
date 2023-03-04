#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 10000 + 5;
const double PI = acos(-1.0);
int T, n, f;
double area[maxn];

bool check(double s) {
    int sum = 0;
    for (int i = 0; i < n; ++i) sum += floor(area[i] / s);
    return sum >= f + 1;
}
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &f);
        double maxs = -1;
        for (int i = 0; i < n; ++i) {
            int r;
            scanf("%d", &r);
            area[i] = PI * r * r;
            maxs = max(maxs, area[i]);
        }

        double l = 0, r = maxs;
        while (r - l > 1e-5) {
            double m = (l + r) / 2;
            if (check(m)) l = m;
            else r = m;
        }
        printf("%.5lf\n", l);
    }
    return 0;
}