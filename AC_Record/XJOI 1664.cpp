//XJOI 1664
#include<bits/stdc++.h>
using namespace std;
long long n, ans;
int main(){
    scanf("%lld", &n);
    ans = 1;
    while(n != 1){
        if(n % 2 == 0) n /= 2; else n = n * 3 + 1;
        ans++;
    }
    printf("%lld", ans);
    return 0;
}