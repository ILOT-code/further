// Uva 11078
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 100000 + 5;
const int INF = 0x3f3f3f3f;
int T, n;
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int premax = -INF, ans = -INF, t;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &t);
            ans = max(ans, premax - t);
            premax = max(premax, t);
        }
        printf("%d\n", ans);
    }
    return 0;
}