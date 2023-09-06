#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 300 + 5;
int n, M;

int main() {
    while (~scanf("%d%d", &M, &n)) {
        printf("%d\n", n * M - 1);
    }
    return 0;
}