// UVa 1073
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1000 + 40;
int n, kase;
long long c[maxn / 2][maxn / 2];

void init() {
    c[0][0] = 1;
    for (int i = 1; i <= 510; ++i) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; ++j) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }
}

int main() {
    init();
    while (~scanf("%d", &n) && n) {
        int x = n / 2 - 2, y = n / 2 + 2;
        printf("Case %d: %lld\n", ++kase, (n < 4 || n % 2) ? 0 : c[y][x] + c[y - 1][x - 1]);
    }
    return 0;
}