//此程序无法通过OJ，由于解的形式不对。但题目给了是输出任意一组解都可以。
//在更改解的输出方式后，可以通过。
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 10000 + 5;
int n, a[maxn];
vector<int> p[maxn];

int main() {
    bool first = true;
    while (~scanf("%d", &n) && n) {
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        sort(a, a + n);
        int k = 0, id = -1, last = 0;
        for (int i = 0; i < n; ++i) {
            if (i == n - 1 || a[i] != a[i + 1]) {
                if (i - last + 1 > k) {
                    k = i - last + 1;
                    id = a[i];
                }
                last = i + 1;
            }
        }
        if (!first)
            puts("");
        else
            first = 0;
        printf("%d\n", k);
        for (int i = 0; i < k; ++i) p[i].clear();
        int pos = -1;
        for (int i = 0; i < n; ++i) {
            if (i == 0 || a[i] == a[i - 1])
                p[++pos].push_back(a[i]);
            else
                p[pos = 0].push_back(a[i]);
        }

        for (int i = 0; i < k; ++i, puts(""))
            for (int j = 0; j < p[i].size(); ++j) {
                if (j != 0) printf(" ");
                printf("%d", p[i][j]);
            }
    }

    return 0;
}