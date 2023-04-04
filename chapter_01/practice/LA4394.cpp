// UVa 1437
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 100 + 5;
char str1[maxn], str2[maxn];
int d[maxn][maxn][30];

int dp(int l, int r, int c) {
    int& ans = d[l][r][c];
    if (ans != -1) return ans;
    if (l > r) return ans = 0;

    int qr = c ? c : (str1[l] - 'a' + 1), re = c ? c : (str1[r] - 'a' + 1);
    if (qr == str2[l] - 'a' + 1) return ans = dp(l + 1, r, c);
    if (re == str2[r] - 'a' + 1) return ans = dp(l, r - 1, c);

    ans = 1 + dp(l + 1, r, c);
    for (int k = l + 1; k <= r; ++k)
        if (str2[k] == str2[l]) ans = min(ans, 1 + dp(l + 1, k - 1, str2[l] - 'a' + 1) + dp(k + 1, r, c));
    return ans;
}
int main() {
    while (~scanf("%s%s", str1, str2)) {
        memset(d, -1, sizeof(d));
        printf("%d\n", dp(0, strlen(str2) - 1, 0));
    }
    return 0;
}