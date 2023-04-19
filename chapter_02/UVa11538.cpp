#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    unsigned long long n, m;
    while (~scanf("%llu%llu", &n, &m) && (n || m)) {
        if (n > m) swap(n, m);
        printf("%llu\n", n * m * (m + n - 2) + 2 * n * (n - 1) * (3 * m - n - 1) / 3);
    }
    return 0;
}
