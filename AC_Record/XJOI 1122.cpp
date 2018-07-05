//XJOI 1122
#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n, ans, t;
    scanf("%lld", &n);
    t = 1; ans = 1;
    for(int i = 2; i <= n; i++){
        t *= i;
        ans += t;
    }
    printf("%lld", ans);
    return 0;
}