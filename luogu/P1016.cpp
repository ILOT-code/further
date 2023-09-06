#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 8 + 2;
int n;
double Dist, col, d, dis[maxn], p[maxn];
struct Oil {
    double rem, p;
} q[maxn];
int front = 0, rear = 0;

int main() {
    scanf("%lf%lf%lf%lf%d", &Dist, &col, &d, &p[0], &n);
    for (int i = 1; i <= n; ++i) scanf("%lf%lf", &dis[i], &p[i]);
    dis[0] = 0, dis[n + 1] = Dist, p[n + 1] = 0;

    double ans = 0, has = 0;
    bool flag = 1;

    double fulld = col * d;
    for (int i = 0; i <= n + 1; ++i) {
        double tod = (i == (n + 1) ? 0 : (dis[i + 1] - dis[i]));
        if (tod > fulld) {
            flag = 0;
            break;
        }
        while (rear > front && q[rear - 1].p > p[i]) {
            ans -= q[rear - 1].rem * q[rear - 1].p;
            has -= q[rear - 1].rem;
            rear--;
        }
        q[rear++] = Oil{col - has, p[i]};
        ans += p[i] * (col - has), has = col;

        while (tod > 1e-6) {
            if (q[front].rem * d >= tod) {
                q[front].rem -= tod / d;
                has -= tod / d;
                break;
            } else {
                tod -= q[front].rem * d;
                has -= q[front].rem * d;
                front++;
            }
        }
    }
    if (flag)
        printf("%.2lf\n", ans);
    else
        printf("No Solution\n");
    return 0;
}
