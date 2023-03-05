// UVa 11520
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 10 + 5;
int T, kase, n;
char mapp[maxn][maxn], list[30];
int left[30], right[30];

void init() {
    for (int i = 1; i <= 26; ++i) list[i] = 'A' + i - 1;
    for (int i = 0; i <= 27; ++i) left[i] = i - 1, right[i] = i + 1;
    left[0] = 0, right[27] = 0;
}

void del(int x) {
    right[left[x]] = right[x];
    left[right[x]] = left[x];
}
void add(int x) {
    right[left[x]] = x;
    left[right[x]] = x;
}
void uniq(int* a, bool* flag, int& cnt) {
    for (int i = 0; i < cnt; ++i)
        for (int j = i + 1; j < cnt; ++j)
            if (a[i] == a[j]) {
                flag[i] = 1;
                break;
            }
}

int main() {
    init();
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%s", mapp[i]);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (mapp[i][j] == '.') {
                    int a[5], cnt = 0;
                    if (i > 0) a[cnt++] = mapp[i - 1][j] - 'A' + 1;
                    if (j > 0) a[cnt++] = mapp[i][j - 1] - 'A' + 1;
                    if (i < n - 1 && mapp[i + 1][j] != '.') a[cnt++] = mapp[i + 1][j] - 'A' + 1;
                    if (j < n - 1 && mapp[i][j + 1] != '.') a[cnt++] = mapp[i][j + 1] - 'A' + 1;
                    bool flag[5] = {0, 0, 0, 0, 0};
                    uniq(a, flag, cnt);
                    for (int i = 0; i < cnt; ++i)
                        if (!flag[i]) del(a[i]);
                    mapp[i][j] = list[right[0]];
                    for (int i = cnt - 1; i >= 0; --i)
                        if (!flag[i]) add(a[i]);
                }
        printf("Case %d:\n", ++kase);
        for (int i = 0; i < n; ++i) printf("%s\n", mapp[i]);
    }
    return 0;
}
