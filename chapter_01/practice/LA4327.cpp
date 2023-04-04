// UVa 1427
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 100 + 5;
const int maxm = 10000 + 5;
int n, m, k, sha[maxn][maxm], sti[maxn][maxm];
int d[maxn][maxm], q[maxm];

void input() {
    for (int i = 1; i <= n + 1; ++i)
        for (int j = 1, t; j <= m; ++j) {
            scanf("%d", &t);
            sha[i][j] = sha[i][j - 1] + t;
        }
    for (int i = 1; i <= n + 1; ++i)
        for (int j = 1, t; j <= m; ++j) {
            scanf("%d", &t);
            sti[i][j] = sti[i][j - 1] + t;
        }
}
int main() {
    while (~scanf("%d%d%d", &n, &m, &k) && (n || m || k)) {
        input();
        for (int i = 1; i <= n + 1; ++i) {
            int front = 0, rear = 0;
            for (int j = 0; j <= m; ++j) {
                while (front < rear && sti[i][j] - sti[i][q[front]] > k) front++;
                d[i][j] = d[i - 1][j];
                if (front < rear) d[i][j] = max(d[i][j], d[i - 1][q[front]] - sha[i][q[front]] + sha[i][j]);
                int t = d[i - 1][j] - sha[i][j];
                while (front < rear && d[i - 1][q[rear - 1]] - sha[i][q[rear - 1]] <= t) rear--;
                q[rear++] = j;
            }

            front = rear = 0;
            for (int j = m; j >= 0; --j) {
                while (front < rear && sti[i][q[front]] - sti[i][j] > k) front++;
                if (front < rear) d[i][j] = max(d[i][j], d[i - 1][q[front]] + sha[i][q[front]] - sha[i][j]);
                int t = d[i - 1][j] + sha[i][j];
                while (front < rear && d[i - 1][q[rear - 1]] + sha[i][q[rear - 1]] <= t) rear--;
                q[rear++] = j;
            }
        }
        int ans = 0;
        for (int i = 0; i <= m; i++) ans = max(ans, d[n + 1][i]);
        printf("%d\n", ans);
    }
    return 0;
}