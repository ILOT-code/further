// UVa 10881
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 10000 + 5;
int K,kase, L, T, n;
struct ANT {
    int id, x, dir;
    bool turn;
    bool operator<(const ANT &rhs) const { return x < rhs.x; }
} ants[maxn], vir[maxn];
bool cmp(ANT &a, ANT &b) { return a.id < b.id; }

int main() {
    scanf("%d", &K);
    while (++kase <= K) {
        scanf("%d%d%d", &L, &T, &n);
        for (int i = 0; i < n; ++i) {
            ants[i].id = i;
            ants[i].turn = false;
            char c;
            scanf("%d %c", &ants[i].x, &c);
            ants[i].dir = c == 'R' ? 1 : -1;
            vir[i].x = ants[i].x + ants[i].dir * T;
            vir[i].dir = ants[i].dir;
        }
        sort(ants, ants + n);
        sort(vir, vir + n);
        for (int i = 0; i < n; ++i) {
            ants[i].x = vir[i].x;
            ants[i].dir = vir[i].dir;
            if ((i > 0 && vir[i].x == vir[i - 1].x) ||
                (i < n - 1 && vir[i].x == vir[i + 1].x))
                ants[i].turn = true;
        }
        sort(ants, ants + n, cmp);
        printf("Case #%d:\n",kase);
        for (int i = 0; i < n; ++i) {
            if (ants[i].x < 0 || ants[i].x > L) printf("Fell off\n");
            else
                printf("%d %s\n", ants[i].x,
                       ants[i].turn ? "Turning"
                                    : (ants[i].dir == 1 ? "R" : "L"));
        }
        printf("\n");
    }
    return 0;
}