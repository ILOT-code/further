// UVa 1030
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define REP(i, n) for (int i = 0; i < (n); ++i)

const int maxn = 10;
int n;
char pos[maxn][maxn][maxn], view[6][maxn][maxn];

char read_char() {
    char ch;
    for (;;) {
        ch = getchar();
        if ((ch >= 'A' && ch <= 'Z') || ch == '.') return ch;
    }
};

void get(int k, int i, int j, int dep, int &x, int &y, int &z) {
    if (k == 0) { x = dep, y = j, z = i; }
    if (k == 1) { x = n - 1 - j, y = dep, z = i; }
    if (k == 2) { x = n - 1 - dep, y = n - 1 - j, z = i; }
    if (k == 3) { x = j, y = n - 1 - dep, z = i; }
    if (k == 4) { x = n - 1 - i, y = j, z = dep; }
    if (k == 5) { x = i, y = j, z = n - 1 - dep; }
}
int main() {
    while (~scanf("%d", &n) && n) {
        REP(i, n) REP(k, 6) REP(j, n) view[k][i][j] = read_char();
        REP(i, n) REP(j, n) REP(k, n) pos[i][j][k] = '#';

        REP(k, 6) REP(i, n) REP(j, n) if (view[k][i][j] == '.') REP(p, n) {
            int x, y, z;
            get(k, i, j, p, x, y, z);
            pos[x][y][z] = '.';
        }

        for (;;) {
            bool done = true;
            REP(k, 6) REP(i, n) REP(j, n) if (view[k][i][j] != '.') {
                REP(p, n) {
                    int x, y, z;
                    get(k, i, j, p, x, y, z);
                    if (pos[x][y][z] == '.') continue;
                    if (pos[x][y][z] == '#') {
                        pos[x][y][z] = view[k][i][j];
                        break;
                    }
                    if (pos[x][y][z] == view[k][i][j]) break;
                    pos[x][y][z] = '.';
                    done = false;
                }
            }
            if (done) break;
        }
        int ans = 0;
        REP(i, n) REP(j, n) REP(k, n) if (pos[i][j][k] != '.') ans++;
        printf("Maximum weight: %d gram(s)\n", ans);
    }
    return 0;
}