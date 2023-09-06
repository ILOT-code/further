#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 30000 + 5;
const int maxm = 5000 + 5;

int n, M, ans;
struct Point {
    int a, b, c;
    bool operator<(const Point& rhs) const { return b < rhs.b; }
} p[maxm];

bool is[maxn];
int main() {
    scanf("%d%d", &n, &M);
    for (int i = 0; i < M; ++i) scanf("%d%d%d", &p[i].a, &p[i].b, &p[i].c);
    sort(p, p + M);

    for (int i = 0; i < M; ++i) {
        int cnt = 0;
        for (int j = p[i].a; j <= p[i].b; ++j) cnt += is[j];
        for (int j = p[i].b; j >= p[i].a && cnt < p[i].c; --j)
            if (!is[j]) is[j] = 1, cnt++, ans++;
    }

    printf("%d\n", ans);
    return 0;
}