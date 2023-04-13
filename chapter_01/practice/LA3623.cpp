// UVa 1375
// 把该文法中所有产生式，转换为 A->BC型
// 对于原来的一个产生式：A->abcdBCD,额外产生 A->空(abcdBCD)
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;

const int maxn = 50 + 5;
const int maxl = 20 + 5;
const int maxs = maxn * 20 + maxn;

int n, len, ns;
string dir[maxs], d[maxs][maxl];
map<string, int> idir;
int head[maxs], tail[maxs];
struct Trans {
    int target, other;
};
vector<Trans> tr[maxs];

int ID(const string& s) {
    if (!idir.count(s)) {
        idir[s] = ns;
        dir[ns++] = s;
    }
    return idir[s];
}
void init() {
    ns = 0;
    idir.clear();
    ID("");
    for (int i = 0; i < maxs; ++i) tr[i].clear();
}
string min(const string& s1, const string& s2) {
    if (s1 == "-") return s2;
    if (s2 == "-") return s1;
    return s1 < s2 ? s1 : s2;
}

bool check(int i, int l) {
    if (dir[i].length() != l) return false;
    for (int p = 0; p < l; ++p)
        if (!islower(dir[i][p])) return false;
    return true;
}

void addedge(const string& s) {
    int id = ID(s);
    if (s.length() < 2) return;
    int front = ID(s.substr(0, 1));
    int rear = ID(s.substr(1));
    tr[front].push_back(Trans{id, rear});
    tr[rear].push_back(Trans{id, front});
    head[id] = front;
    tail[id] = rear;
}

typedef pair<string, int> PSI;
bool vis[maxs];
void dirjstra(int l) {
    memset(vis, 0, sizeof(vis));
    priority_queue<PSI, vector<PSI>, greater<PSI>> que;
    for (int i = 0; i < ns; ++i)
        if (d[i][l] != "-") que.push(PSI(d[i][l], i));

    while (!que.empty()) {
        PSI tmp = que.top();
        que.pop();
        if (vis[tmp.second]) continue;
        vis[tmp.second] = 1;

        for (int i = 0; i < tr[tmp.second].size(); ++i) {
            Trans v = tr[tmp.second][i];
            if (d[v.other][0] != "-" && (d[v.target][l] == "-" || tmp.first < d[v.target][l])) {
                d[v.target][l] = tmp.first;
                que.push(PSI(d[v.target][l], v.target));
            }
        }
    }
}

int main() {
    while (cin >> n >> len && n) {
        init();
        string s;
        for (int i = 0; i < n; ++i) {
            cin >> s;
            int left = ID(s.substr(0, 1));
            int right = ID(s.substr(2));
            tr[right].push_back(Trans{left, 0});
            tr[0].push_back(Trans{left, right});
            head[left] = 0, tail[left] = right; // 这是可以省略的，但为了整体的一致性，加上
            for (int j = 2; j < s.length(); ++j) addedge(s.substr(j));
        }

        for (int j = 0; j < len + 1; ++j)
            for (int i = 0; i < ns; ++i)
                if (check(i, j))
                    d[i][j] = dir[i];
                else
                    d[i][j] = "-";

        for (int j = 0; j < len + 1; ++j) {
            for (int i = 0; i < ns; ++i) {
                // 对于空串和字母的终结符，不会被更新
                // 对于那些大写字母，它的左串是空的，下一个for循环中不会运行
                // 这样可以节省对head,tail数组的初始化
                if (dir[i].length() < 2) continue;
                for (int k = 1; k < j; ++k)
                    if (d[head[i]][k] != "-" && d[tail[i]][j - k] != "-") d[i][j] = min(d[i][j], d[head[i]][k] + d[tail[i]][j - k]);
            }
            dirjstra(j);
        }
        cout << d[ID("S")][len] << endl;
    }
    return 0;
}