// NWERC2007 LA3971
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <vector>
using namespace std;
#define fi first
#define se second
typedef pair<int, int> PII;

const int maxn = 1000 + 5;
int T, n, b;

int cnt;
map<string, int> id;
vector<PII> con[maxn];
int ID(string s) {
    if (!id.count(s)) id[s] = cnt++;
    return id[s];
}

bool check(int x) {
    int sum = 0;
    for (int i = 0; i < cnt; ++i) {
        int cheap = b + 1;
        for (int j = 0; j < con[i].size(); ++j)
            if (con[i][j].se >= x) cheap = min(cheap, con[i][j].fi);
        if (cheap == b + 1) return false;
        if ((sum += cheap) > b) return false;
    }
    return true;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &b);
        id.clear(), cnt = 0;
        for (int i = 0; i < n; ++i) con[i].clear();
        int maxq = 0, p, q;
        char type[30], name[30];
        for (int i = 0; i < n; ++i) {
            scanf("%s%s%d%d", type, name, &p, &q);
            maxq = max(maxq, q);
            con[ID(type)].push_back(PII(p, q));
        }

        int l = 0, r = maxq + 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (check(m)) l = m + 1;
            else r = m;
        }
        printf("%d\n", l - 1);
    }
    return 0;
}