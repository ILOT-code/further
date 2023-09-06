#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
typedef unsigned long long ull;
ull A, B;
int main() {
    scanf("%llu%llu", &A, &B);
    while ((A | (A + 1)) <= B) A |= (A + 1);
    int ans = 0;
    while (A) ans += A & 1, A >>= 1;
    printf("%d\n", ans);
    return 0;
}