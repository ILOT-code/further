#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 5000 + 5;
int n, po[maxn][2];
struct Node {
    int r, d, idx;
    bool operator<(const Node& rhs) const { return d > rhs.d; }
} x[maxn], y[maxn];

bool cmp(const Node& a, const Node& b) { return a.r < b.r; }

bool valid(Node* x, int flag) {
    priority_queue<Node> q;

    int pos = 1;
    for (int i = 1; i <= n; ++i) {
        while (pos <= n && x[pos].r <= i) q.push(x[pos++]);
        if (q.empty()) return false;
        Node tmp = q.top();
        q.pop();
        if (tmp.d < i) return false;
        po[tmp.idx][flag] = i;
    }
    return true;
}

int main() {
    while (~scanf("%d", &n) && n) {
        for (int i = 1; i <= n; ++i) scanf("%d%d%d%d", &x[i].r, &y[i].r, &x[i].d, &y[i].d);
        for (int i = 1; i <= n; ++i) x[i].idx = y[i].idx = i;
        sort(x + 1, x + 1 + n, cmp);
        sort(y + 1, y + 1 + n, cmp);

        bool flag = valid(x, 0) * valid(y, 1);
        if (flag)
            for (int i = 1; i <= n; ++i) printf("%d %d\n", po[i][0], po[i][1]);
        else
            printf("IMPOSSIBLE\n");
    }
    return 0;
}