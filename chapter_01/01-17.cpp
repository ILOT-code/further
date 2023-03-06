// UVa 11462
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
using namespace std;

int n, cnt[101];

inline int read() {
    char c = getchar();
    while (!isdigit(c)) c = getchar();
    int x = 0;
    while (isdigit(c)) {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}
int buf[10];
inline void write(int x) {
    int p = 0;
    if (x == 0) p++;
    else while (x) {
            buf[p++] = x % 10;
            x /= 10;
        }
    for (int i = p - 1; i >= 0; --i) putchar(buf[i] + '0');
}
int main() {
    while (n = read()) {
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; ++i) cnt[read()]++;
        bool first = 1;
        for (int i = 1; i <= 100; ++i)
            for (int j = 0; j < cnt[i]; ++j) {
                if (!first) putchar(' ');
                write(i);
                first = 0;
            }
        printf("\n");
    }
    return 0;
}