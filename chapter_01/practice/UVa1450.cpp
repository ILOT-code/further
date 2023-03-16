// 网上的题解千篇一律，但我认为都是错的，文尾附上一个反例。
// 其实就是have有问题，have指的是两者公共都可以飞出飞机的数量，应该比任意一方现存飞机数大。
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 5000 + 5;
int T, n, w[maxn], e[maxn];
// 改正的judge
bool judge(int lim) {
    int sumw, sume, have;
    sumw = sume = have = 0;
    for (int i = 0; i < n; i++) {
        sumw += w[i], sume += e[i];
        int overw = max(sumw - lim, 0);
        int overe = max(sume - lim, 0);
        if (overw + overe > have) return false;
        if (sumw > have && sume > have)
            have++;
        else if (sumw > have && sume <= have)
            sumw--;
        else if (sume > have && sumw <= have)
            sume--;
    }
    return true;
}
/*bool judge(int lim) {
    int sumw, sume, have;
    sumw = sume = have = 0;
    for (int i = 0; i < n; i++) {
        sumw += w[i], sume += e[i];
        int overw = max(sumw - lim, 0);
        int overe = max(sume - lim, 0);
        if (overw + overe > have) return false;
        if (sumw == 0 && sume > 0)
            sume--;
        else if (sume == 0 && sumw > 0)
            sumw--;
        else if (sumw && sume && sumw + sume > have)
            have++;
    }
    return true;
}*/

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int maxv = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &w[i], &e[i]);
            maxv += max(w[i], e[i]);
        }
        int L = 1, R = maxv;
        while (L < R) {
            int M = (L + R) / 2;
            if (judge(M)) R = M;
            else L = M + 1;
        }
        printf("%d\n", L - 1);
    }
    return 0;
}
/*
1
6
1 1
1 0
1 0
1 0
0 5
*/
// 很容易由这个例子看出，网上的题解都是错的
