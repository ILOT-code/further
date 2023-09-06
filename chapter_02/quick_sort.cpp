#include <algorithm>
#include <cstdio>
#include <cstring>

const int maxn = 1000 + 5;
int n, A[maxn];

void swap(int& a, int& b) {
    int t = a;
    a = b, b = t;
}
int sep(int l, int r) {
    if (r - l <= 1) return r;
    int p = l, pp = l - 1;
    while (p < r) {
        if (A[p] <= A[r - 1] && ++pp != p) swap(A[p], A[pp]);
        p++;
    }
    return pp;
}

void quick_sort(int l, int r) {
    if (r - l <= 1) return;
    int re = sep(l, r);
    quick_sort(l, re), quick_sort(re + 1, r);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &A[i]);
    quick_sort(0,n);
    for(int i = 0; i < n; ++i) printf("%d ",A[i]);
}