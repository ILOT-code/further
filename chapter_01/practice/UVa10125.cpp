#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
typedef pair<int, int> PII;

const int maxn = 1000 + 5;
int n, a[maxn];
map<int, pair<int, int>> vis;

int main() {
    while (~scanf("%d", &n) && n) {
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        sort(a, a + n);
        vis.clear();
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if (!vis.count(a[i] + a[j])) vis[a[i] + a[j]] = PII(i, j);
                
        bool flag = false;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                if (j == i) continue;
                int t = a[i] - a[j];
                if (vis.count(t)) {
                    PII p = vis[t];
                    if (i != p.first && i != p.second && j != p.first && j != p.second) {
                        printf("%d\n", a[i]);
                        flag = true;
                        break;
                    }
                }
            }
            if (flag) break;
        }
        if (!flag) printf("no solution\n");
    }
    return 0;
}