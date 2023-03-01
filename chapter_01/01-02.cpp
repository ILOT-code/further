// UVA 11729
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define fi first
#define se second
typedef pair<int, int> PII;

const int maxn = 1000;
int n, T;
PII a[maxn];
int main() {
    while (~scanf("%d", &n) && n) {
        for (int i = 0; i < n; ++i) scanf("%d%d", &a[i].se, &a[i].fi);
        sort(a, a + n);
        int ans = 0, sum = 0;
        for (int i = n - 1; i >= 0; --i) {
            sum += a[i].se;
            ans = max(ans, sum + a[i].fi);
        }
        printf("Case %d: %d\n", ++T, ans);
    }
    return 0;
}