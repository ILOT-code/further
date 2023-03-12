#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define fi first
#define se second
typedef pair<int, bool> PIB;

const int maxn = 500000 + 5;
int T, n;
PIB a[maxn];
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i].fi);
            a[i].se = a[i].fi >= 0 ? 1 : 0;
            a[i].fi = abs(a[i].fi);
        }
        sort(a, a + n);

        int ans = 0, last = -1;
        for (int i = 0; i < n; ++i)
            if (last == -1 || a[i].se != last) ans++, last = a[i].se;
        printf("%d\n", ans);
    }
    return 0;
}