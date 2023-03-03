// UVa 11384
// 如果数堆中有i(i>1)个一样的数，则可以等价为只有一个该数
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
int solve(int x) { return x == 1 ? 1 : solve(x / 2) + 1; }
int main() {
    while (~scanf("%d", &n)) printf("%d\n", solve(n));
    return 0;
}