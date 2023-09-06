// NEERC 2006, 100287G
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

int n, M;
int main() {
    while (~scanf("%d%d", &n, &M)) {
        double ans = 0;
        for (int i = 0; i < n; ++i) {
            double t = (double)i * (n + M) / n;
            ans += fabs(t - floor(t + 0.5)) / (n + M);
        }
        printf("%.4lf\n", ans * 10000);
    }
    return 0;
}