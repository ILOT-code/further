#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 100 + 5;
const int maxs = 8;
int s, m, n;
int slary[maxn], tea[maxn], d[maxn][1 << (2 * maxs)];

void change_st(int& old, int sta) {
    for (int i = 0; i < s; ++i)
        if (sta & (1 << i)) {
            if (old & (1 << (2 * i)))
                old ^= (1 << (2 * i));
            else if (old & (1 << (2 * i + 1)))
                old ^= (1 << (2 * i + 1));
        }
}

int dp(int p, int state) {
    if (d[p][state] != -1) return d[p][state];
    int& ans = d[p][state];
    if (state == 0) return ans = 0;
    if (p == 0) return ans = INF;
    ans = dp(p - 1, state);
    change_st(state, tea[p]);
    return ans = min(ans, dp(p - 1, state) + slary[p]);
}

int main() {
    while (~scanf("%d%d%d", &s, &m, &n) && s) {
        int sum = 0, state = (1 << (2 * s)) - 1;
        for (int i = 0; i < m; ++i) {
            char c;
            int tmptea = 0, t;
            scanf("%d%c", &t, &c);
            sum += t;
            while (c != '\n') {
                scanf("%d%c", &t, &c);
                tmptea |= (1 << (t - 1));
            }
            change_st(state, tmptea);
        }
        for (int i = 1, t; i <= n; ++i) {
            char c;
            scanf("%d%c", &slary[i], &c);
            tea[i] = 0;
            while (c != '\n') {
                scanf("%d%c", &t, &c);
                tea[i] |= (1 << (t - 1));
            }
        }
        memset(d, -1, sizeof(d));
        printf("%d\n", dp(n, state) + sum);
    }
    return 0;
}