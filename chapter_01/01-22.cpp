// UVa 1330
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1000 + 5;
int T, m, n;
bool g[maxn][maxn];
int up[maxn], left[maxn], right[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &m, &n);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                char ch = getchar();
                while (ch != 'F' && ch != 'R') ch = getchar();
                g[i][j] = ch == 'F' ? 0 : 1;
            }

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            int ld = -1, rd = n;
            for (int j = 0; j < n; ++j) {
                if (g[i][j]) {
                    up[j] = left[j] = 0;
                    ld = j;
                } else {
                    up[j] = i == 0 ? 1 : up[j] + 1;
                    left[j] = i == 0 ? ld + 1 : max(left[j], ld + 1);
                }
            }
            for (int j = n - 1; j >= 0; --j) {
                if (g[i][j]) {
                    right[j] = n;
                    rd = j;
                } else {
                    right[j] = i == 0 ? rd - 1 : min(right[j], rd - 1);
                    ans = max(ans, up[j] * (right[j] - left[j] + 1));
                }
            }
        }
        printf("%d\n", ans * 3);
    }
    return 0;
}