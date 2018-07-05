//XJOI 1702
#include<bits/stdc++.h>
using namespace std;
long long n;
int main(){
    scanf("%lld", &n);
    long long l = 1, r = 2000000000, ans;
    long double x;
    while(l < r){
        ans = (l + r) / 2;
        x = 1 + (long double) ans * log10(ans);
        if(x >= n) r = ans; else l = ans + 1;
    }
    printf("%lld", l);
    return 0;
}