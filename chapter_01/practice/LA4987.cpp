// UVa 1474
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define fi first
#define se second
typedef pair<int, int> PII;

const int maxn = 4000 + 5;
const long long INF = 1e18;
int n, M, ans[maxn];
long long d[2][maxn];
PII a[maxn], b[maxn];
bool cho[maxn][maxn];

void print(int i, int j) {
    if (i == 0) return;
    print(i - 1, j - cho[i][j]);
    ans[a[i].se] = b[j].se;
}
int main() {
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i].fi), a[i].se = i;
        scanf("%d", &M);
        for (int i = 1; i <= M; ++i) scanf("%d", &b[i].fi), b[i].se = i;
        sort(a + 1, a + n + 1);
        sort(b + 1, b + M + 1);
        d[0][1] = abs(a[1].fi - b[1].fi);
        d[0][0] = d[0][2] = INF;
        bool t = 1;
        for (int i = 2; i <= n; ++i, t ^= 1) {
            d[t][0] = d[t][min(i, M) + 1] = INF;
            for (int j = 1; j <= min(i, M); ++j) {
                d[t][j] = abs(a[i].fi - b[j].fi);
                cho[i][j] = d[t ^ 1][j - 1] < d[t ^ 1][j];
                d[t][j] += cho[i][j] ? d[t ^ 1][j - 1] : d[t ^ 1][j];
            }
        }
        printf("%lld\n", d[t ^ 1][M]);
        print(n, M);
        for (int i = 1; i <= n; ++i) printf("%d%c", ans[i], i == n ? '\n' : ' ');
    }
    return 0;
}