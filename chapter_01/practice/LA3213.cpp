// UVa 1339
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 100 + 10;
char s1[maxn], cnt1[30], s2[maxn], cnt2[30];

int main() {
    while (~scanf("%s", s1)) {
        scanf("%s", s2);
        memset(cnt1, 0, sizeof(cnt1));
        memset(cnt2, 0, sizeof(cnt2));
        for (int i = 0; s1[i] != '\0'; ++i) cnt1[s1[i] - 'A']++;
        for (int i = 0; s2[i] != '\0'; ++i) cnt2[s2[i] - 'A']++;
        bool flag = 1;
        sort(cnt1, cnt1 + 26);
        sort(cnt2, cnt2 + 26);
        for (int i = 0; i < 26; ++i)
            if (cnt1[i] != cnt2[i]) {
                flag = false;
                break;
            }
        printf("%s\n", flag ? "YES" : "NO");
    }
    return 0;
}