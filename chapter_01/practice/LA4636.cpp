// UVa 1445
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 20 + 2;
int w, d, hx[maxn], hy[maxn];

int main() {
    while (~scanf("%d%d", &w, &d) && (w || d)) {
        memset(hx, 0, sizeof(hx));
        memset(hy, 0, sizeof(hy));
        for (int i = 0, t; i < w; ++i) {
            scanf("%d", &t);
            hx[t]++;
        }
        for (int i = 0, t; i < d; ++i) {
            scanf("%d", &t);
            hy[t]++;
        }
        int ans = 0;
        for (int i = 0; i < maxn; ++i) ans += max(hx[i], hy[i]) * i;
        printf("%d\n", ans);
    }
    return 0;
}