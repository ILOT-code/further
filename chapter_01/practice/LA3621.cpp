// UVa 1374
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1000 + 10;
int n, have[maxn];

bool dfs(int d, int step) {
    if (d > step) return false;
    if (have[d] == n) return true;
    if (have[d] << (step - d) < n) return false;
    for (int i = 0; i <= d; i++) {
        have[d + 1] = have[d] + have[i];
        if (have[d] <= 2 * maxn && dfs(d + 1, step)) return true;
        have[d + 1] = have[d] - have[i];
        if (have[d] > 0 && dfs(d + 1, step)) return true;
    }
    return 0;
}

int main() {
    have[0] = 1;
    while (~scanf("%d", &n) && n) {
        for (int i = 0;; i++)
            if (dfs(0, i)) {
                printf("%d\n", i);
                break;
            }
    }
    return 0;
}