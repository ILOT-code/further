#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1000 + 5;

int n, A[maxn], B[maxn];

void merge_sort(int l, int r) {
    if (r - l <= 1) return;
    int mid = (l + r) / 2;
    merge_sort(l, mid), merge_sort(mid, r);
    for (int i = l; i < r; ++i) A[i] = B[i];

    int pl = l, pr = mid, p = l;
    while (pl != mid && pr != r) {
        if (A[pl] <= A[pr])
            B[p++] = A[pl++];
        else
            B[p++] = A[pr++];
    }

    if (pl != mid)
        for (; pl != mid; pl++) B[p++] = A[pl];
    else
        for (; pr != r; pr++) B[p++] = A[pr];
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &A[i]), B[i] = A[i];
    merge_sort(0, n);
    for (int i = 0; i < n; ++i) printf("%d ", B[i]);
}