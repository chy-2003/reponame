//XJOI 1115
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int main(){
    LL n, ans;
    scanf("%lld", &n);
    ans = 0;
    for(int i = 1; i <= n; i++)
     ans += (i % 7 == 0)? i : 0;
    printf("%lld", ans);
    return 0;
}