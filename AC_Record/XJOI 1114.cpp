//XJOI 1114
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int main(){
    LL minnum, maxnum, n, t;
    scanf("%lld", &n);
    minnum = 1e18;
    maxnum = -1e18;
    for(int i = 1; i <= n; i++){
        scanf("%lld", &t);
        minnum = min(minnum, t);
        maxnum = max(maxnum, t);
    }
    printf("%lld\n%lld\n", maxnum, minnum);
    return 0;
}