#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1000 + 5;
int T, d[maxn];
bool is[maxn][maxn];
char s[maxn];
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%s", &s);
        int n = strlen(s);
        for (int len = 1; len < n; ++len)
            for (int i = 0; i < n + 1 - len; ++i) {
                int j = i + len - 1;
                if (len == 1) is[i][j] = true;
                else if (len == 2) is[i][j] = s[i] == s[j];
                else is[i][j] = (s[j] == s[i]) && is[i + 1][j - 1];
            }

        for (int i = 0; i < n; ++i) {
            d[i] = i + 1;
            if (is[0][i]) { d[i] = 1; continue; }
            for (int j = 1; j <= i; ++j)
                if (is[j][i]) d[i] = min(d[i], 1 + d[j - 1]);
        }
        printf("%d\n", d[n - 1]);
    }
    return 0;
}