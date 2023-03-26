#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 500000 + 5;
int n;
struct Student {
    int x, y;
    bool flag;
    void standard() {
        if (x > y)
            swap(x, y), flag = false;
        else
            flag = true;
    }
    bool operator<(const Student& rhs) {
        if (x == rhs.x) return y < rhs.y;
        return x < rhs.x;
    }
} a[maxn];
int main() {
    while (~scanf("%d", &n) && n) {
        for (int i = 0, x, y; i < n; ++i) {
            scanf("%d%d", &a[i].x, &a[i].y);
            a[i].standard();
        }
        bool ans = true;
        if (n % 2 == 1)
            ans = false;
        else {
            sort(a, a + n);
            int last = 0, c[2] = {0, 0};
            for (int i = 0; i < n; ++i) {
                if (a[i].x == a[last].x && a[i].y == a[last].y) {
                    c[a[i].flag]++;
                    if (i == n - 1) ans = c[0] == c[1];
                } else {
                    if (c[0] == c[1]) {
                        last = i;
                        c[0] = c[1] = 0;
                        c[a[i].flag]++;
                    } else {
                        ans = false;
                        break;
                    }
                }
            }
        }
        if (ans)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}