#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 300 + 5;
int n, m;

int main() {
    while (~scanf("%d%d", &m, &n)) {
        printf("%d\n", n * m - 1);
    }
    return 0;
}