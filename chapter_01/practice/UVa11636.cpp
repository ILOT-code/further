#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int kase, n;
int main() {
    while (~scanf("%d", &n) && n > 0) {
        int ans = 0, sum = 1;
        while (sum <= n / 2) {
            ans++;
            sum *= 2;
        }
        ans += (n - sum) ? 1 : 0;
        printf("Case %d: %d\n", ++kase, ans);
    }
    return 0;
}