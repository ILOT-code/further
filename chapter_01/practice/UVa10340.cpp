#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1000000;
char s[maxn], t[maxn];
int main() {
    while (~scanf("%s%s", t, s)) {
        int p1 = 0, p2 = 0;
        bool flag = false;
        for (; s[p2] != 0; ++p2) {
            if (s[p2] == t[p1]) p1++;
            if (t[p1] == 0) {
                flag = true;
                break;
            }
        }
        printf("%s\n", flag ? "Yes" : "No");
    }
    return 0;
}