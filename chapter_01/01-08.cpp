// UVa 1352
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

const int maxn = 4;
const int left[] = {4, 0, 2, 3, 5, 1}; // left[i]表示执行左旋操作时，原第i方位面现在指向的方位
const int up[] = {2, 1, 5, 0, 4, 3};
int n, ans;
int pose[24][6], col[maxn][6];
int r[maxn], clast[maxn][6]; // clast[i][j]表示，第i个立方体在选择一种pose后，j方位的颜色

vector<string> names;
int ID(char* name) {
    string s(name);
    int n = names.size();
    for (int i = 0; i < n; ++i)
        if (names[i] == s) return i;
    names.push_back(s);
    return n;
}

void rot(const int* R, int* p) {
    for (int i = 0; i < 6; ++i) p[i] = R[p[i]];
}
void generate() {
    int p0[6] = {0, 1, 2, 3, 4, 5}, p[6]; // p[i]表示原i面现在的方位
    for (int i = 0; i < 6; ++i) {
        memcpy(p, p0, sizeof(p));
        if (i == 0) rot(up, p);
        if (i == 1) rot(left, p), rot(up, p);
        if (i == 3) rot(up, p), rot(up, p);
        if (i == 4) rot(left, p), rot(left, p), rot(left, p), rot(up, p);
        if (i == 5) rot(left, p), rot(left, p), rot(up, p);

        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 6; ++k) pose[i * 4 + j][k] = p[k];
            rot(left, p);
        }
    }
}

void check() {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 6; ++j) clast[i][pose[r[i]][j]] = col[i][j];
    int sum = 0, cnt[6 * maxn];
    for (int j = 0; j < 6; ++j) {
        memset(cnt, 0, sizeof(cnt));
        int maxc = 0;
        for (int i = 0; i < n; ++i) maxc = max(maxc, ++cnt[clast[i][j]]);
        sum += n - maxc;
    }
    ans = min(ans, sum);
}
void dfs(int d) {
    if (d == n) check();
    else
        for (int i = 0; i < 24; ++i) {
            r[d] = i;
            dfs(d + 1);
        }
}

int main() {
    generate();
    while (~scanf("%d", &n) && n) {
        names.clear();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < 6; ++j) {
                char name[30];
                scanf("%s", name);
                col[i][j] = ID(name);
            }
        ans = 6 * n;
        r[0] = 0;
        dfs(1);
        printf("%d\n", ans);
    }
    return 0;
}