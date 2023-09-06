#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 100000 + 10;
int n, nx;

struct Line {
    int x1, y1, x2, y2;
    double k;
    void init() {
        k = (double)(y1 - y2) / (x1 - x2);
        if (x2 < x1) swap(x1, x2), swap(y1, y2);
    }
} line[maxn];

int main() {
    scanf("%d%d", &n, &nx);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d%d", &line[i].x1, &line[i].y1, &line[i].x2, &line[i].y2);
        line[i].init();
    }

    double ny = (1e9 + 10);
    while (1) {
        double miny = -(1e9 + 10);
        int pos = -1;
        for (int i = 0; i < n; ++i)
            if (line[i].x1 < nx && line[i].x2 > nx) {
                double tmpy = line[i].y1 + line[i].k * (nx - line[i].x1);
                if (tmpy > miny && tmpy <= ny) pos = i, miny = tmpy;
            }

        if (pos == -1) break;
        if (line[pos].y1 < line[pos].y2)
            nx = line[pos].x1, ny = line[pos].y1;
        else
            nx = line[pos].x2, ny = line[pos].y2;
    }

    printf("%d\n", nx);
    return 0;
}