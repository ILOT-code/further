#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
using namespace std;
typedef long long LL;

const int limit = 10000;
const int maxc = 9;
const int maxk = 100;

int C, S;
int X[maxc], K[maxc], Y[maxc][maxk], bestc;

set<int> values[maxc];
void solve() {
    for (int i = 0; i < C; ++i) {
        if (i == bestc) continue;
        values[i].clear();
        for (int j = 0; j < K[i]; ++j) values[i].insert(Y[i][j]);
    }

    for (int k = 0; S > 0; ++k)
        for (int i = 0; i < K[bestc]; ++i) {
            LL t = 1ll * k * X[bestc] + Y[bestc][i];

            if (t == 0) continue;
            bool ok = true;
            for (int j = 0; j < C; ++j) {
                if (j == bestc) continue;
                if (!values[j].count(t % X[j])) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                printf("%lld\n", t);
                if (--S == 0) break;
            }
        }
}

void gcd(LL a, LL b, LL& d, LL& x, LL& y) {
    if (!b)
        d = a, x = 1, y = 0;
    else
        gcd(b, a % b, d, y, x), y -= x * (a / b);
}
// n 个方程：x=a[i](mod m[i]) (0<=i<n)
LL china(int n, int* a, int* m) {
    LL M = 1, d, y, x = 0;
    for (int i = 0; i < n; ++i) M *= m[i];
    for (int i = 0; i < n; ++i) {
        LL w = M / m[i];
        gcd(m[i], w, d, d, y);
        x = (x + y * w * a[i]) % M;
    }
    return (x + M) % M;
}

vector<LL> ans;
int a[maxc];

void dfs(int d) {
    if (d == C)
        ans.push_back(china(C, a, X));
    else
        for (int i = 0; i < K[d]; ++i) {
            a[d] = Y[d][i];
            dfs(d + 1);
        }
}

void solve_china() {
    ans.clear();
    dfs(0);
    sort(ans.begin(), ans.end());
    LL M = 1;
    for (int i = 0; i < C; ++i) M *= X[i];
    for (int k = 0; S > 0; ++k)
        for (int i = 0; i < ans.size(); ++i) {
            LL t = k * M + ans[i];
            if (t == 0) continue;
            printf("%lld\n", t);
            if (--S == 0) break;
        }
}

int main() {
    while (~scanf("%d%d", &C, &S) && C) {
        bestc = 0;
        LL tot = 1;
        for (int i = 0; i < C; ++i) {
            scanf("%d%d", &X[i], &K[i]);
            tot *= K[i];
            for (int j = 0; j < K[i]; ++j) scanf("%d", &Y[i][j]);
            sort(Y[i], Y[i] + K[i]);
            if (K[i] * X[bestc] < K[bestc] * X[i]) bestc = i;
        }
        if (tot > limit)
            solve();
        else
            solve_china();
        printf("\n");
    }
    return 0;
}