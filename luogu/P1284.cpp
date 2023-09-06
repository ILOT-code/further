#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 40 + 5;
int n, l[maxn];
bool f[810][810];

double Helen(double i, double j, double k) {
    double p;
    p = (i + j + k) / 2;
    return sqrt(p * (p - i) * (p - j) * (p - k));
}
bool check(int i, int j, int k) { return i + j > k && i + k > j && j + k > i; }
int main() {
    scanf("%d", &n);
    int sum = 0;
    for (int i = 1; i <= n; ++i) scanf("%d", &l[i]), sum += l[i];
    f[0][0] = 1;

    for (int i = 1; i <= n; ++i)
        for (int j = sum / 2; j >= 0; --j)
            for (int k = j; k >= 0; --k)
                if ((j >= l[i] && (f[j - l[i]][k] || f[k][j - l[i]])) || (k >= l[i] && f[j][k - l[i]])) f[j][k] = 1;

    double ans = -1.0;
    for (int i = sum / 2; i >= 1; --i)
        for (int j = i; j >= 1; --j)
            if (f[i][j] && check(i, j, sum - i - j)) {
                double s = Helen(i, j, sum - i - j);
                ans = max(s, ans);
            }

    if (ans < 0)
        printf("-1\n");
    else
        printf("%d\n", (int)(100 * ans));

    return 0;
}