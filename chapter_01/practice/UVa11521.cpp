#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 200 + 5;
char s[maxn];
int d[maxn][maxn], b[maxn][maxn];
int f[maxn][maxn][maxn], x[maxn][maxn][maxn], y[maxn][maxn][maxn];
bool e[maxn][maxn][maxn];

void print(int i, int j) {
    int l = b[i][j];
    if (l < 0) {
        for (int k = i; k <= j; ++k) printf("%c", s[k]);
        return;
    }
    if (l < j) {
        print(i, l), print(l + 1, j);
        return;
    }
    l >>= 9;

    printf("["), print(i, i + l - 1), printf("]%d", x[l][i][j]);
    int k = i, c = 0;
    while (y[l][k][j]) {
        c++;
        // 左边的串不会写在x[l][i][j]中。
        if (k + l <= y[l][k][j] - 1) printf("{"), print(k + l, y[l][k][j] - 1), printf("}%d", c);
        k = y[l][k][j];
    }
    if (k + l <= j - l) printf("{"), print(k + l, j - l), printf("}%d", ++c);
}

int main() {
    while (~scanf("%s", s + 1)) {
        int n = strlen(s + 1);
        for (int len = 1; len <= n; ++len) {
            for (int i = 1, j = i + len - 1; j <= n; ++i, ++j) {
                d[i][j] = len, b[i][j] = -1;
                for (int k = i - len; k > 0; --k) e[len][k][i] = s[k] == s[i] && (len == 1 || e[len - 1][k + 1][i + 1]);
                for (int k = i; k < j; ++k) {
                    int v = d[i][k] + d[k + 1][j];
                    if (v < d[i][j]) d[i][j] = v, b[i][j] = k;

                    int ll = k - i + 1;
                    if (2 * ll <= len && e[ll][i][j - ll + 1]) {
                        int c = d[i][k] + 3;
                        f[ll][i][j] = c + (2 * ll < len ? (d[k + 1][j - ll] + 3) : 0);
                        x[ll][i][j] = 2, y[ll][i][j] = 0;

                        for (int p = k + 1; p <= j - 2 * ll + 1; ++p)
                            if (e[ll][i][p]) {
                                v = f[ll][i][p + ll - 1] + f[ll][p][j] - c;
                                if (v < f[ll][i][j]) {
                                    f[ll][i][j] = v;
                                    x[ll][i][j] = x[ll][i][p + ll - 1] + x[ll][p][j] - 1;
                                    y[ll][i][j] = p;
                                }
                            }
                        // 下面的更新取小于号，那么左边的任意子串是不会被划分到x中的。
                        if (f[ll][i][j] < d[i][j]) d[i][j] = f[ll][i][j], b[i][j] = ll << 9;
                    }
                }
            }
        }

        printf("%d ", d[1][n]);
        print(1, n);
        printf("\n");
    }
    return 0;
}