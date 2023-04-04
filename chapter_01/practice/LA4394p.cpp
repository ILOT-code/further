// UVa 1437
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 100 + 5;
int d[maxn][maxn], g[maxn];
char str1[maxn], str2[maxn];

int main() {
    while (~scanf("%s%s", &str1, &str2)) {
        int len = strlen(str1);
        for (int i = 0; i < len; ++i) d[i][i] = 1;
        for (int l = 2; l <= len; ++l) {
            for (int i = 0; i + l - 1 < len; ++i) {
                int j = i + l - 1;
                d[i][j] = 1 + d[i + 1][j];
                if (str2[i] == str2[j])
                    d[i][j] = d[i][j - 1];
                else
                    for (int k = i + 1; k <= j; ++k)
                        if (str2[k] == str2[i]) d[i][j] = min(d[i][j], d[i + 1][k] + d[k + 1][j]);
            }
        }

        for (int i = 0; i < len; i++) {
            g[i] = d[0][i];
            if (str1[i] == str2[i]) {
                if (i == 0)
                    g[i] = 0;
                else
                    g[i] = g[i - 1];
            } else
                for (int j = 0; j <= i; j++) g[i] = min(g[i], g[j] + d[j + 1][i]);
        }
        printf("%d\n", g[len - 1]);
    }
    return 0;
}