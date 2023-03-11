// UVa 1169
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 100000 + 10;
int T, c, n;
int x[maxn], y[maxn];
int totol_dist[maxn], totol_weight[maxn], dist2origin[maxn];
int q[maxn], d[maxn];

int func(int i) { return d[i] - totol_dist[i + 1] + dist2origin[i + 1]; }
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &c, &n);
        for (int i = 1, w; i <= n; ++i) {
            scanf("%d%d%d", &x[i], &y[i], &w);
            dist2origin[i] = abs(x[i]) + abs(y[i]);
            totol_weight[i] = totol_weight[i - 1] + w;
            totol_dist[i] = totol_dist[i - 1] + abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]);
        }

        int front = 0, rear = 0, ready = 1;
        q[rear++] = 0; // 不转运
        for (int i = 1; i <= n; ++i) {
            while (ready < i) {
                int val = func(ready);
                while (front < rear && val <= func(q[rear - 1])) rear--;
                q[rear++] = ready++;
            }
            while (front < rear && totol_weight[i] - totol_weight[q[front]] > c) front++;
            d[i] = func(q[front]) + totol_dist[i] + dist2origin[i];
        }
        printf("%d\n", d[n]);
        if (T) printf("\n");
    }
    return 0;
}