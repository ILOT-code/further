#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define fi first
#define se second
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

const int maxn = 10000 + 5;
int n, l, w;
double t;
PII p[maxn];
vector<PDD> ve;

void push(int i) {
    if (2 * p[i].se < w) return;
    double delta = sqrt((double)((double)p[i].se * p[i].se) - t);
    ve.push_back(PDD(p[i].fi - delta, p[i].fi + delta));
}
int main() {
    while (~scanf("%d%d%d", &n, &l, &w)) {
        t = (double)w / 2 * w / 2;
        ve.clear();
        for (int i = 0; i < n; ++i) scanf("%d%d", &p[i].fi, &p[i].se);
        for (int i = 0; i < n; ++i) push(i);
        sort(ve.begin(), ve.end());
        double last = 0.0;
        int cnt = 0, flag = 0;
        for (int i = 0; i < ve.size();) {
            double lon = 0;
            if (ve[i].fi > last) {
                flag = 1;
                break;
            }
            while (i < ve.size() && ve[i].fi <= last) {
                lon = max(lon, ve[i].se);
                ++i;
            }
            last = lon;
            cnt++;
            if (last > l) break;
        }
        if (last < l) flag = 1;
        printf("%d\n", flag ? -1 : cnt);
    }
    return 0;
}