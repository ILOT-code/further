// UVa 1069
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn = 100 + 5;

LL c[maxn], d;
char s[maxn * maxn];
LL power(LL x, int n, LL MOD) {
    LL ans = 1;
    while (n) {
        if (n & 1) ans = (ans * x) % MOD;
        x = (x * x) % MOD;
        n /= 2;
    }
    return ans;
}

bool isdigital(char a) { return a >= '0' && a <= '9'; }
void init() {
    memset(c, 0, sizeof(c));
    int len = strlen(s);
    int flag = 0, negative = 0;
    LL a[3] = {0, 0, 0};
    for (int i = 0; i < len; ++i) {
        if (isdigital(s[i])) a[flag] = 10 * a[flag] + s[i] - '0';
        if (s[i] == '+' || s[i] == '-') {
            if (flag == 2) {
                negative = s[i] == '-';
                continue;
            }
            if (i != 0) c[a[1]] = negative ? -a[0] : a[0];
            a[1] = a[0] = 0;
            negative = s[i] == '-';
            flag = 0;
        }
        if (s[i] == 'n') {
            flag = 1;
            if (s[i + 1] != '^') a[1] = 1;
            if (i == 1 || !isdigital(s[i - 1])) a[0] = 1;
        }
        if (s[i] == '/') {
            c[a[1]] = negative ? -a[0] : a[0];
            a[1] = a[0] = 0;
            negative = 0;
            flag = 2;
        }
        if (i == len - 1) d = negative ? -a[2] : a[2];
    }
}

bool judge() {
    int n = maxn - 1;
    while (c[n] == 0) n--;
    for (int i = 1; i <= n + 1; ++i) {
        LL ans = 0;
        for (int j = 0; j <= n; ++j)
            if (c[j]) ans = (ans + c[j] * power(i, j, d)) % d;
        if (ans) return false;
    }
    return true;
}

int main() {
    int kase = 0;
    while (~scanf("%s", s) && s[0] != '.') {
        init();
        printf("Case %d: %s\n", ++kase, judge() ? "Always an integer" : "Not always an integer");
    }
    return 0;
}