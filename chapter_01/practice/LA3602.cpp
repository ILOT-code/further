// UVa 1368
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1000 + 5;
const int maxm = 50 + 5;
int T, n, m, cnt[30];
char ans[maxn], s[maxm][maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) scanf("%s", s[i]);
        int sum = 0;
        for (int j = 0; j < m; ++j) {
            memset(cnt, 0, sizeof(cnt));
            for (int i = 0; i < n; ++i) cnt[s[i][j] - 'A']++;
            int t = 0, id = 100;
            for (int i = 0; i < 26; ++i)
                if (cnt[i] > t || (cnt[i] == t && i < id)) t = cnt[i], id = i;
            ans[j] = id + 'A';
            for (int i = 0; i < 26; ++i) sum += i == id ? 0 : cnt[i];
        }
        for (int i = 0; i < m; ++i) printf("%c", ans[i]);
        printf("\n%d\n", sum);
    }
    return 0;
}