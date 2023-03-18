// UVa 1344
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1000 + 5;
int n, ti[maxn], ki[maxn];

int solve(int T, int t, int K, int k) {
    if (T < t || K < k) return 0;
    if (ti[T] > ki[K]) return 1 + solve(T - 1, t, K - 1, k);
    if (ti[T] < ki[K]) return -1 + solve(T, t + 1, K - 1, k);
    if (ti[t] <= ki[k]) return (ti[t] < ki[K] ? -1 : 0) + solve(T, t + 1, K - 1, k);
    return 1 + solve(T, t + 1, K, k + 1);
}

int main() {
    while (~scanf("%d", &n) && n) {
        for (int i = 0; i < n; ++i) scanf("%d", &ti[i]);
        for (int i = 0; i < n; ++i) scanf("%d", &ki[i]);
        sort(ti, ti + n);
        sort(ki, ki + n);
        printf("%d\n", 200 * solve(n - 1, 0, n - 1, 0));
    }
    return 0;
}