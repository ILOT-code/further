// UVa 1451
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 100000 + 10;
int T, n, L, sum[maxn], q[maxn];
char s[maxn];
int cmp(int x1, int x2, int x3, int x4) { return (sum[x2] - sum[x1]) * (x4 - x3) - (sum[x4] - sum[x3]) * (x2 - x1); }

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%s", &n, &L, s + 1);
        for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + s[i] - '0';
        
        int ansL = 0, ansR = L;
        int front = 0, rear = 0;
        for (int i = L; i <= n; ++i) {
            int r = i - L;
            while (rear - front > 1 && cmp(q[rear - 2], r, q[rear - 1], r) >= 0) rear--;
            q[rear++] = r;
            while (rear - front > 1 && cmp(q[front], i, q[front + 1], i) <= 0) front++;
            int t = cmp(q[front], i, ansL, ansR);
            if (t > 0 || (t == 0 && i - q[front] < ansR - ansL)) ansL = q[front], ansR = i;
        }

        printf("%d %d\n", ansL + 1, ansR);
    }
    return 0;
}