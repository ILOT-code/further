#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 100000 + 5;
const int INF = 0x3f3f3f3f;
int n, m, sx, sy;
int cnt, head[2 * maxn];

struct Line {
    int h, l, r;
    bool operator<(const Line& rhs) const { return h > rhs.h; }
} p[maxn];
struct Edge {
    int v, w, nxt;
} e[2 * maxn];
void addedge(int u, int v, int w) { e[++cnt] = Edge{v, w, head[u]}, head[u] = cnt; }

bool vis[2 * maxn];
void build() {
    int s = 0;
    for (; s < n; ++s)
        if (p[s].h < sy && p[s].l < sx && p[s].r > sx) break;
    addedge(2 * n + 1, s, sx - p[s].l), addedge(2 * n + 1, s + n, p[s].r - sx);
    queue<int> q;
    q.push(s), vis[s] = 1;

    while (!q.empty()) {
        int i = q.front();
        q.pop();
        bool left = 0, right = 0;
        for (int j = i + 1; p[i].h - p[j].h <= m && j <= n; ++j) {
            if (!left && p[i].l > p[j].l && p[i].l < p[j].r) {
                left = 1;
                addedge(i, j, p[i].l - p[j].l);
                addedge(i, j + n, p[j].r - p[i].l);
                if (!vis[j]) q.push(j), vis[j] = 1;
            }
            if (!right && p[i].r < p[j].r && p[i].r > p[j].l) {
                right = 1;
                addedge(i + n, j + n, p[j].r - p[i].r);
                addedge(i + n, j, p[i].r - p[j].l);
                if (!vis[j]) q.push(j), vis[j] = 1;
            }
            if (right && left) break;
        }
        if (!left && p[i].h <= m) addedge(i, 2 * n, 0);
        if (!right && p[i].h <= m) addedge(i + n, 2 * n, 0);
    }
}

int dis[2 * maxn];
void SPFA() {
    memset(dis, INF, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    dis[2 * n + 1] = 0, vis[2 * n + 1] = 1, q.push(2 * n + 1);

    while (!q.empty()) {
        int u = q.front();
        q.pop(), vis[u] = 0;
        for (int ev = head[u]; ev; ev = e[ev].nxt) {
            int v = e[ev].v, w = e[ev].w;
            if (dis[v] > w + dis[u]) {
                dis[v] = w + dis[u];
                if (!vis[v]) q.push(v);
            }
        }
    }
}

int main() {
    scanf("%d%d%d%d", &n, &m, &sx, &sy);
    for (int i = 0; i < n; ++i) scanf("%d%d%d", &p[i].h, &p[i].l, &p[i].r);
    sort(p, p + n);
    build(), SPFA();
    printf("%d\n", sy + dis[2 * n]);
    return 0;
}