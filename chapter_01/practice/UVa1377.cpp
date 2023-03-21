#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
using namespace std;
typedef set<int>::iterator iter;

const int maxn = 50 + 5;
const int maxm = 1000000 + 5;
int kase, n, nc, d[maxn], v[maxm];
struct state {
    int s;        // 可满足的刻度
    set<int> rec; // 刻度线集合
};                // 在任意时刻，该刻度线集合的全部可能排列包含了s.
set<int> ans;

void init() {
    nc = 0;
    ans.clear();
    memset(v, -1, sizeof(v));
    for (int i = 0, t; i < n; ++i) {
        scanf("%d", &t);
        if (v[t] == -1) {
            d[nc++] = t;
            v[t] = 1;
        }
    }
    sort(d, d + nc);
    for (int i = 0; i < nc; ++i) v[d[i]] = i;
}

bool cmp(state u) {
    if (u.rec.size() != ans.size()) return u.rec.size() < ans.size();
    return *u.rec.rbegin() < *ans.rbegin();
}
state add(state u, int k) {
    for (iter it = u.rec.begin(); it != u.rec.end(); ++it) {
        int t = abs(*it - k);
        if (v[t] != -1) u.s |= 1 << v[t];
    }
    u.rec.insert(k);
    return u;
}

void bfs() {
    int end = (1 << nc) - 1, m = d[nc - 1];
    queue<state> q;            //队列中元素的rec.size()是递增的
    state sta;
    sta.s = 0, sta.rec.insert(0);
    q.push(sta);

    while (!q.empty()) {
        state u = q.front(); q.pop();

        if ((ans.size() != 0 && u.rec.size() > ans.size()) || u.rec.size() >= 7) return;
        if (u.s == end && (ans.size() == 0 || cmp(u))) ans = u.rec;
        else {
            for (int i = 0; i < nc; ++i)  {
                if (u.s & (1 << i)) continue;
                for (iter it = u.rec.begin(); it != u.rec.end(); ++it) {
                    if (*it + d[i] <= m) q.push(add(u, *it + d[i]));
                    if (*it - d[i] > 0) q.push(add(u, *it - d[i]));
                }
            }
        }
    }
}

void solve() {
    bfs();
    printf("Case %d:\n", ++kase);
    printf("%d\n", ans.size());
    bool flag = false;
    for (iter it = ans.begin(); it != ans.end(); ++it) {
        if (flag) printf(" ");
        printf("%d", *it);
        flag = true;
    }
    printf("\n");
}
int main() {
    while (~scanf("%d", &n) && n) {
        init();
        solve();
    }
    return 0;
}