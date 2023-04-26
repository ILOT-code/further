#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;

const int maxn = 4000000 + 5;
LL phi[maxn], s[maxn], f[maxn];

void get_phi() {
    phi[1] = 1;
    for (int i = 2; i < maxn; ++i)
        if (!phi[i])
            for (int j = i; j < maxn; j += i) {
                if (!phi[j]) phi[j] = j;
                phi[j] = phi[j] / i * (i - 1);
            }
}
inline void init() {
    get_phi();
    for (int i = 1; i < maxn; ++i)
        for (int j = 2 * i; j < maxn; j += i) f[j] += i * phi[j / i];

    s[2] = f[2];
    for (int i = 3; i < maxn; ++i) s[i] = s[i - 1] + f[i];
}

int main() {
    init();
    int n;
    while (~scanf("%d", &n) && n) printf("%lld\n", s[n]);
    return 0;
}