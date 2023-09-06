#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 20000 + 5;
const int maxm = 100000 + 5;
int n, M, fa[maxn], enemy[maxn];

struct Point {
    int a, b, c;
    bool operator<(const Point& rhs) { return c > rhs.c; }
} p[maxm];

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
int main() {
    scanf("%d%d", &n, &M);
    for (int i = 1; i <= n; ++i) fa[i] = i;
    for (int i = 0; i < M; ++i) scanf("%d%d%d", &p[i].a, &p[i].b, &p[i].c);
    sort(p, p + M);

    for (int i = 0; i <= M; ++i) {
        int x = p[i].a, y = p[i].b, z = p[i].c;
        if (find(x) == find(y)) {
            printf("%d\n", z);
            break;
        }
        if (enemy[x])
            fa[find(y)] = fa[find(enemy[x])];
        else
            enemy[x] = y;
        if (enemy[y])
            fa[find(x)] = fa[find(enemy[y])];
        else
            enemy[y] = x;
    }
    return 0;
}