//XJOI 1194
#include<bits/stdc++.h>
using namespace std;
long long sqr(long long x){
    return x * x;
}
bool is_prime(long long x){
    if(x < 2) return false;
    for(int i = 2; i * i <= x; i++)
     if(x % i == 0) return false;
    return true;
}
int main(){
    long long n;
    while(scanf("%lld", &n) == 1){
        if((sqr(sqrt(n)) == n) &&
           (is_prime(sqrt(n)))) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}