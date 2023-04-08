// UVa 1439
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 100 + 5;
const int INF = 0x3f3f3f3f;
const int maxk = 15;
int n, U[maxn], V[maxn], e[maxk], clolor[maxk];
int ind[1 << maxk], d[1 << maxk], best[1 << maxk];

int get_last(int s) {
    int i = 0;
    while ((s & (1 << i)) == 0) i++;
    return i;
}

int main() {
    while (~scanf("%d", &n)) {
        getchar();
        memset(e, 0, sizeof(e));
        int useful = 0;
        for (int i = 0; i < n; ++i) {
            char u, v;
            scanf("%c %c", &u, &v), getchar();
            u -= 'L', v -= 'L';
            U[i] = u, V[i] = v;
            e[u] |= (1 << v), e[v] |= (1 << u);
            useful |= (1 << u), useful |= (1 << v);
        }

        ind[0] = 1;
        for (int i = 1; i <= useful; ++i) {
            int j = i & (-i), t = get_last(i);
            ind[i] = ind[i ^ j] && (e[t] & (i ^ j)) == 0;
        }

        memset(d, INF, sizeof(d));
        d[0] = 0;
        for (int i = 1; i <= useful; ++i)
            for (int j = i; j; j = (j - 1) & i)
                if (ind[j])
                    if (d[i ^ j] + 1 < d[i]) best[i] = j, d[i] = d[i ^ j] + 1;

        printf("%d\n", d[useful] - 2);
        int s = useful, k = 0;
        while (s) {
            for (int i = 0; (1 << i) <= s; ++i)
                if (best[s] & (1 << i)) clolor[i] = k;
            k++, s = s ^ best[s];
        }
        for (int i = 0; i < n; ++i) {
            if (clolor[U[i]] < clolor[V[i]]) swap(U[i], V[i]);
            printf("%c %c\n", 'L' + U[i], 'L' + V[i]);
        }
    }
    return 0;
}