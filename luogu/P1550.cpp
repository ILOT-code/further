#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 300 + 5;
int n, w[maxn], cnt, ans;
int fa[maxn];
struct Edge {
    int u, v, c;
    bool operator<(const Edge& rhs) { return c < rhs.c; }
} e[maxn * maxn];

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
int main() {
    scanf("%d", &n);
    for (int i = 0; i <= n; ++i) fa[i] = i;
    for (int i = 0; i < n; ++i) scanf("%d", &w[i]), e[cnt++] = Edge{i, n, w[i]};
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            int t;
            scanf("%d", &t);
            if (j > i) e[cnt++] = Edge{i, j, t};
        }

    sort(e, e + cnt);

    cnt = 0;
    for (int i = 0; cnt < n; ++i) {
        int fx = find(e[i].u), fy = find(e[i].v);
        if (fx == fy) continue;
        ans += e[i].c;
        fa[fx] = fy;
        cnt++;
    }
    printf("%d\n", ans);

    return 0;
}