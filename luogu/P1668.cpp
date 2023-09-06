#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 25000 + 5;
int n, T;
struct Point {
    int s, e;
    bool operator<(const Point& rhs) { return s < rhs.s; }
} p[maxn];
int main() {
    scanf("%d%d", &n, &T);
    for (int i = 0; i < n; ++i) scanf("%d%d", &p[i].s, &p[i].e);
    sort(p, p + n);
    int ans = 0, rear = 1, nrear = 0;

    for (int i = 0; i < n; ++i) {
        if (p[i].s <= rear) nrear = max(nrear, p[i].e);
        if (nrear >= T) break;

        if (p[i].s > rear) {
            if (rear == nrear + 1) {
                ans = -1;
                break;
            }
            rear = nrear + 1;
            ans++;
            i--;
        }
    }

    if (nrear >= T)
        ans++;
    else
        ans = -1;
    printf("%d\n", ans);

    return 0;
}