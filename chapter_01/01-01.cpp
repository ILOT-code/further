// UVa 11292
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 20000;
int n, M, a[maxn], b[maxn];
int main() {
    while (~scanf("%d%d", &n, &M) && (n != 0 || M != 0)) {
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        for (int i = 0; i < M; ++i) scanf("%d", &b[i]);
        sort(a, a + n);
        sort(b, b + M);
        int ans = 0, flag = 1;
        for (int i = 0, j = 0; i < n; ++i) {
            while (j < M && b[j] < a[i]) j++;
            if (j == M) { flag = 0; break; }
            ans += b[j++];
        }
        if (flag) printf("%d\n", ans);
        else printf("Loowater is doomed!\n");
    }
    return 0;
}