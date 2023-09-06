// UVa 1394
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 10000 + 5;
int n, k, M, res;
int main() {
    while (~scanf("%d%d%d", &n, &k, &M) && n) {
        res = 0;
        for (int i = 1; i <= n - 1; ++i) res = (res + k) % i;
        printf("%d\n", (res + M) % n + 1);
    }
    return 0;
}