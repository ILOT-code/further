// UVa 12099
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 70 + 5;
const int INF = 0x3f3f3f3f;
int T, n, d[2100 + 50][2100 + 50], prew[maxn];
struct BOOK {
    int h, w;
    bool operator<(const BOOK& rhs) { return h > rhs.h; }
} book[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int sumw = 0, maxw = n * 30, ans = INF;
        for (int i = 0; i < n; ++i) scanf("%d%d", &book[i].h, &book[i].w), sumw += book[i].w;
        sort(book, book + n);
        prew[0] = book[0].w;
        for (int i = 1; i < n; ++i) prew[i] = prew[i - 1] + book[i].w;
        memset(d, INF, sizeof(d));

        d[0][0] = 0;
        for (int i = 1; i < n; ++i)
            for (int j = (prew[i] + 30) / 2; j >= 0; --j)
                for (int k = min(j + 30, prew[i] - 2 * j + 30); k >= 0; --k)
                    if (d[j][k] != INF) {
                        d[j + book[i].w][k] = min(d[j + book[i].w][k], d[j][k] + (j == 0 ? book[i].h : 0));
                        d[j][k + book[i].w] = min(d[j][k + book[i].w], d[j][k] + (k == 0 ? book[i].h : 0));
                    }

        for (int j = (prew[n - 1] + 30) / 2; j >= 1; --j)
            for (int k = min(j + 30, prew[n - 1] - 2 * j + 30); k >= 1; --k)
                if (d[j][k] != INF) ans = min(ans, (book[0].h + d[j][k]) * (max(sumw - j - k, max(j, k))));
        printf("%d\n", ans);
    }
    return 0;
}