#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 30000 + 5;

int k, M;
int ans[7 * maxn], nxt[7 * maxn], cnt, rear;
priority_queue<int, vector<int>, greater<int>> q;

int main() {
    scanf("%d%d", &k, &M);
    q.push(1);
    while (cnt < k) {
        int x = q.top(), d = 0;
        cnt++;
        q.pop();
        q.push(2 * x + 1), q.push(4 * x + 5);
        while (x) {
            d = d * 10 + x % 10;
            x /= 10;
        }
        while (d) {
            ans[++rear] = d % 10;
            d /= 10;
        }
    }
    for (int i = 1; i <= rear; ++i) printf("%d", ans[i]), nxt[i] = i + 1;
    printf("\n");

    ans[rear + 1] = -1, nxt[0] = 1;

    while (M) {
        int i = 0;
        while (nxt[i] <= rear) {
            if (ans[nxt[i]] < ans[nxt[nxt[i]]]) {
                nxt[i] = nxt[nxt[i]];
                M--;
                break;
            }
            i = nxt[i];
        }
    }
    for (int i = nxt[0]; i <= rear; i = nxt[i]) printf("%d", ans[i]);
    return 0;
}