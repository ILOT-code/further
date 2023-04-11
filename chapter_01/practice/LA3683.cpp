// UVa 1380
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int maxn = 200 + 5;
const int INF = 0x3f3f3f3f;
int n, maxlen, d[maxn], f[maxn], g[maxn];
struct Edge {
    int u, v, t; // uv是一条边，t=0代表u->v，t=1代表v->u，t=2代表无向
    Edge(int u = 0, int v = 0, int t = -1) : u(u), v(v), t(t) {}
};
vector<Edge> G[maxn];
struct Unson {
    int v, f, g;
    Unson(int v = 0, int f = 0, int g = 0) : v(v), f(f), g(g) {}
};
bool cmpf(const Unson& a, const Unson& b) { return a.f < b.f; }
bool cmpg(const Unson& a, const Unson& b) { return a.g < b.g; }

bool readData() {
    for (int i = 1; i < maxn; ++i) G[i].clear();
    n = 0;
    int u, v, t;
    string str;
    while (cin >> u) {
        if (u == 0) break;
        while (cin >> str) {
            if (str[0] == '0') break;
            if (str.back() == 'd') {
                v = stoi(str.substr(0, str.length() - 1));
                G[u].push_back(Edge(u, v, 0));
                G[v].push_back(Edge(v, u, 1));
            } else if (str.back() == 'u') {
                v = stoi(str.substr(0, str.length() - 1));
                G[u].push_back(Edge(u, v, 1));
                G[v].push_back(Edge(v, u, 0));
            } else {
                v = stoi(str);
                G[u].push_back(Edge(u, v, 2));
                G[v].push_back(Edge(v, u, 2));
            }
            ++n;
        }
    }
    ++n;
    return n != 1;
}

void dfs(int u, int pa) {
    d[u] = f[u] = g[u] = 0;
    for (int i = 0; i < G[u].size(); ++i) {
        int &v = G[u][i].v, &t = G[u][i].t;
        if (v == pa) continue;
        dfs(v, u);
        if (t == 0) g[u] = max(g[u], 1 + g[v]);
        if (t == 1) f[u] = max(f[u], 1 + f[v]);
        d[u] = max(d[u], d[v]);
    }
    d[u] = max(d[u], f[u] + g[u]);
}

bool dp(int u, int pa) {
    f[u] = g[u] = 0;
    vector<Unson> unsons;
    for (int i = 0; i < G[u].size(); ++i) {
        int &v = G[u][i].v, &t = G[u][i].t;
        if (v == pa) continue;
        if (!dp(v, u)) return false;
        if (t == 0) g[u] = max(g[u], 1 + g[v]);
        if (t == 1) f[u] = max(f[u], 1 + f[v]);
        if (t == 2) unsons.push_back(Unson(v, f[v], g[v]));
    }
    if (f[u] + g[u] > maxlen) return false;
    if (unsons.empty()) return true;

    int f1 = INF, g1 = INF;
    int maxg[n];
    sort(unsons.begin(), unsons.end(), cmpf);
    maxg[unsons.size() - 1] = unsons[unsons.size() - 1].g;
    for (int i = unsons.size() - 2; i >= 0; --i) maxg[i] = max(maxg[i + 1], unsons[i].g);
    for (int i = 0; i <= unsons.size(); ++i) {
        int ff = i > 0 ? max(f[u], unsons[i - 1].f + 1) : f[u];
        int gg = i < unsons.size() ? max(g[u], maxg[i] + 1) : g[u];
        if (ff + gg <= maxlen) f1 = min(f1, ff);
    }

    int maxf[n];
    sort(unsons.begin(), unsons.end(), cmpg);
    maxf[unsons.size() - 1] = unsons[unsons.size() - 1].f;
    for (int i = unsons.size() - 2; i >= 0; --i) maxf[i] = max(maxf[i + 1], unsons[i].f);
    for (int i = 0; i <= unsons.size(); ++i) {
        int gg = i > 0 ? max(g[u], unsons[i - 1].g + 1) : g[u];
        int ff = i < unsons.size() ? max(f[u], maxf[i] + 1) : f[u];
        if (ff + gg <= maxlen) g1 = min(g1, gg);
    }
    f[u] = f1, g[u] = g1;
    return f[u] < INF;
}

int main() {
    while (readData()) {
        dfs(1, -1);
        maxlen = d[1];
        printf("%d\n", maxlen + 1 + !dp(1, -1));
    }
    return 0;
}
