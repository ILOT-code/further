// UVa 10795
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;

const int maxn = 60 + 5;
int n, kase, sta[maxn], des[maxn];

LL f(int* p, int i, int final) {
    if (!i) return 0;
    if (p[i] == final) return f(p, i - 1, final);
    return f(p, i - 1, 6 - p[i] - final) + (1LL << (i - 1));
}

int main() {
    while (~scanf("%d", &n) && n) {
        for (int i = 1; i <= n; ++i) scanf("%d", &sta[i]);
        for (int i = 1; i <= n; ++i) scanf("%d", &des[i]);
        int k = n;
        while (k && sta[k] == des[k]) k--;
        LL ans = 0;
        if (k) {
            int t = 6 - sta[k] - des[k];
            ans = f(sta, k - 1, t) + 1 + f(des, k - 1, t);
        }
        printf("Case %d: %lld\n", ++kase, ans);
    }
    return 0;
}