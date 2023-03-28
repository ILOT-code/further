// UVa 1392
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 150000 + 5;
int n, p;
char a[maxn], b[maxn];
struct Node {
    int v, id;
    bool operator<(const Node& rhs) const { return v < rhs.v || (v == rhs.v && id > rhs.id); }
} po[maxn];

int main() {
    while (~scanf("%d%d", &n, &p) && n) {
        scanf("%s%s", a + 1, b + 1);
        int sum = 0;
        po[0].id = 0, po[0].v = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i] != b[i]) sum++;
            po[i].v = 100 * sum - p * i;
            po[i].id = i;
        }
        sort(po, po + n + 1);
        int ans = 0, rmax = po[0].id;
        for (int i = 1; i <= n; ++i) {
            if (po[i].id > rmax) rmax = po[i].id;
            else ans = max(ans, rmax - po[i].id);
        }

        if (ans) printf("%d\n", ans);
        else printf("No solution.\n");
    }
    return 0;
}