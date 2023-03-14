// UVa 1422
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 10000 + 5;
int T, n, maxd;
struct Node {
    int r, d, w;
    bool operator<(const Node& rhs) const { return d > rhs.d; }
} po[maxn];

bool cmp(const Node& x, const Node& y) { return x.r < y.r || (x.r == y.r && x.d < y.d); }

bool check(int m) {
    priority_queue<Node> q;
    int pos = 0;
    for (int i = 1; i <= maxd; ++i) {
        while (pos < n && po[pos].r < i) q.push(po[pos++]);
        int remain = m;
        while (remain > 0 && !q.empty()) {
            Node tmp = q.top();
            q.pop();
            if (tmp.d < i) return false;
            if (tmp.w <= remain)
                remain -= tmp.w;
            else {
                tmp.w -= remain;
                q.push(tmp);
                break;
            }
        }
    }
    if (pos == n && q.empty()) return true;
    return false;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        maxd = 0;
        for (int i = 0; i < n; ++i) scanf("%d%d%d", &po[i].r, &po[i].d, &po[i].w), maxd = max(maxd, po[i].d);
        sort(po, po + n, cmp);
        int l = 1, r = 1000 * 5;
        while (l < r) {
            int m = (l + r) / 2;
            if (check(m)) r = m;
            else l = m + 1;
        }
        printf("%d\n", l);
    }
    return 0;
}