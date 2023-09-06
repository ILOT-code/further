#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 500 + 5;
int M, k, a[maxn], sum, ans[2 * maxn];

bool check(int x) {
    int ret = 0, cnt = 1;
    for (int i = 0; i < M; ++i) {
        ret += a[i];
        if (ret > x) {
            if (a[i] <= x)
                cnt++, ret = a[i];
            else
                return false;
        }
    }
    return cnt <= k;
}
int main() {
    scanf("%d%d", &M, &k);
    for (int i = 0; i < M; ++i) scanf("%d", &a[i]), sum += a[i];
    int l = 0, r = sum;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }

    int ret = 0, rear = M - 1, pos = 0;
    for (int i = M - 1; i >= 0; --i) {
        ret += a[i];
        if (ret > l) {
            ret = a[i];
            ans[pos++] = rear + 1;
            ans[pos++] = i + 2;
            rear = i;
        }
    }
    ans[pos++] = rear + 1, ans[pos++] = 1;

    for (int i = k; i >= 1; --i) printf("%d %d\n", ans[2 * i - 1], ans[2 * i - 2]);
    return 0;
}