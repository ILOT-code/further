// 既然142857是(m,n)=(6,10)的解，那1428570为什么不是(m,n)=(7,10)的一个解？
// 这题的表诉有问题？
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 400 + 5;
const int maxm = 7 + 2;
int n, M;
int d[maxm], p[maxm], c[maxm], ans[maxm], cnt[maxn], vis[maxn];

bool check() {
    for (int i = 0; i < M; ++i) ans[i] = c[i] = d[p[i]];
    c[M] = 0;
    for (int i = 2; i <= M; ++i) {
        for (int j = 0; j < M; ++j) {
            c[j + 1] += (c[j] + ans[j]) / n;
            c[j] = (c[j] + ans[j]) % n;
        }
        if (c[M] != 0) return false;
        memset(vis, 0, sizeof(vis));
        for (int j = 0; j < M; ++j) vis[c[j]]++;
        for (int j = 0; j < M; ++j)
            if (vis[c[j]] != cnt[c[j]]) return false;
    }
    return true;
}

bool dfs(int cur) {
    if (cur == M) return check();
    for (int i = cur; i < M; ++i) {
        swap(p[i], p[cur]);
        if (dfs(cur + 1)) return true;
        swap(p[i], p[cur]);
    }
    return false;
}
bool judge(int last) {
    int tmp = 0;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < M; ++i) {
        tmp = (tmp + last) % n;
        d[i] = tmp;
    }
    for (int i = 0; i < M; ++i) p[i] = i, cnt[d[i]]++;
    return dfs(1);
}

int main() {
    while (~scanf("%d%d", &M, &n) && (M || n)) {
        bool flag = false;
        for (int i = 1; i < n; ++i) {
            if (judge(i)) {
                flag = true;
                break;
            }
        }
        if (!flag)
            printf("Not found.\n");
        else
            for (int i = M - 1; i >= 0; i--) printf("%d%c", ans[i], i ? ' ' : '\n');
    }
    return 0;
}