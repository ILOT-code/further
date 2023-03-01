// UVa 11300
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;

const int maxn = 1000000;
int n;
LL a[maxn], c[maxn], sum, ver, ans;
int main() {
    while (~scanf("%d", &n)) {
        //if(n == 0) {printf("error\n"); continue;}
        sum = 0, ans = 0;
        for (int i = 0; i < n; ++i) scanf("%lld", &a[i]), sum += a[i];
        ver = sum / n;
        for (int i = 1; i < n; ++i) c[i] = c[i - 1] + a[i - 1] - ver;
        sort(c, c + n);
        LL mid = c[n / 2];
        for (int i = 0; i < n; ++i) ans += abs(c[i] - mid);
        printf("%lld\n", ans);
    }
    return 0;
}