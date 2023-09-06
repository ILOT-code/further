// UVa 1412
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

const int maxn = 8;
const int maxm = 100 + 5;
const int maxstate = 15000;
const double INF = 1e30;

int kase, M, n, kk, s[maxn], k[maxn];
double c, price[maxn][maxm], d[maxm][maxstate];
char name[maxn][10];
int buy_next[maxstate][maxn], sell_next[maxstate][maxn];
int opt[maxm][maxstate], Prev[maxm][maxstate];
vector<vector<int>> states;
map<vector<int>, int> ID;

void dfs(int pos, vector<int>& sta, int tot) {
    if (pos == n) {
        states.push_back(sta);
        ID[sta] = states.size() - 1;
        return;
    }
    for (int i = 0; i <= k[pos] && i + tot <= kk; ++i) {
        sta[pos] = i;
        dfs(pos + 1, sta, tot + i);
    }
}

void init() {
    ID.clear();
    states.clear();
    vector<int> sta(n);
    dfs(0, sta, 0);

    for (int s = 0; s < states.size(); ++s) {
        int totlot = 0;
        for (int i = 0; i < n; ++i) totlot += states[s][i];
        for (int i = 0; i < n; ++i) {
            buy_next[s][i] = sell_next[s][i] = -1;
            if (states[s][i] < k[i] && totlot < kk) {
                vector<int> newstate = states[s];
                newstate[i]++;
                buy_next[s][i] = ID[newstate];
            }
            if (states[s][i] > 0) {
                vector<int> newstate = states[s];
                newstate[i]--;
                sell_next[s][i] = ID[newstate];
            }
        }
    }
}

void update(int oldday, int olds, int news, double v, int op) {
    if (v > d[oldday + 1][news]) {
        d[oldday + 1][news] = v;
        opt[oldday + 1][news] = op;
        Prev[oldday + 1][news] = olds;
    }
}

double dp() {
    for (int day = 0; day <= M; ++day)
        for (int s = 0; s < states.size(); s++) d[day][s] = -INF;
    d[0][0] = c;
    for (int day = 0; day < M; ++day)
        for (int s = 0; s < states.size(); ++s) {
            double v = d[day][s];
            if (v < -1) continue;
            update(day, s, s, v, 0);
            for (int i = 0; i < n; i++) {
                if (buy_next[s][i] >= 0 && v >= price[i][day + 1] - 1e-3) update(day, s, buy_next[s][i], v - price[i][day + 1], i + 1);
                if (sell_next[s][i] >= 0) update(day, s, sell_next[s][i], v + price[i][day + 1], -i - 1);
            }
        }
    return d[M][0];
}
void print_ans(int day, int s) {
    if (day == 0) return;
    print_ans(day - 1, Prev[day][s]);
    if (opt[day][s] == 0)
        printf("HOLD\n");
    else if (opt[day][s] > 0)
        printf("BUY %s\n", name[opt[day][s] - 1]);
    else
        printf("SELL %s\n", name[-opt[day][s] - 1]);
}
int main() {
    while (~scanf("%lf%d%d%d", &c, &M, &n, &kk)) {
        for (int i = 0; i < n; ++i) {
            scanf("%s%d%d", name[i], &s[i], &k[i]);
            for (int j = 1; j <= M; ++j) scanf("%lf", &price[i][j]), price[i][j] *= s[i];
        }
        init();
        if (kase++ > 0) printf("\n");
        printf("%.2lf\n", dp());
        print_ans(M, 0);
    }
    return 0;
}