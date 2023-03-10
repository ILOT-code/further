// UVa 1326
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

const int maxn = 24;
int n, a[maxn];
map<int, int> table;
int bitcount(int x) { return x == 0 ? 0 : bitcount(x >> 1) + (x & 1); }

int main() {
    while (~scanf("%d", &n) && n) {
        for (int i = 0; i < n; ++i) {
            a[i] = 0;
            char s[100];
            scanf("%s", s);
            for (int j = 0; s[j] != '\0'; ++j) a[i] ^= (1 << (s[j] - 'A'));
        }
        table.clear();
        int n1 = n / 2, n2 = n - n1;
        for (int i = 0; i < (1 << n1); ++i) {
            int x = 0;
            for (int j = 0; j < n1; ++j)
                if (i & (1 << j)) x ^= a[j];
            if (!table.count(x) || bitcount(table[x]) < bitcount(i)) table[x] = i;
        }
        int ans = 0;
        for (int i = 0; i < (1 << n2); ++i) {
            int x = 0;
            for (int j = 0; j < n2; ++j)
                if (i & (1 << j)) x ^= a[n1 + j];
            if (table.count(x) && bitcount(ans) < bitcount(i) + bitcount(table[x])) ans = table[x] ^ (i << n1);
        }
        printf("%d\n", bitcount(ans));
        for (int i = 0; i < n; ++i)
            if (ans & (1 << i)) printf("%d ", i + 1);
        printf("\n");
    }
    return 0;
}