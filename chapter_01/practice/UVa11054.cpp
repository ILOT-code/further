#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100000 + 5;
int n;
int main(){
    while(~scanf("%d",&n) && n){
        long long ans = 0, ret = 0;
        for(int i = 0,t; i < n; ++i){
            scanf("%d",&t);
            ret += t;
            ans += abs(ret);
        }
        printf("%lld\n",ans);
    }
    return 0;
}