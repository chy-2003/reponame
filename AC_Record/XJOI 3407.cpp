#include<bits/stdc++.h>
using namespace std;
const long long Mo = 1000000009;
long long n, m, k, t;
long long expow(long long k, long long x){
    if(x == 0) return 1;
    long long t = expow(k, x / 2);
    t = t * t % Mo;
    if(x % 2 == 1) t = t * k % Mo;
    return t;
}
int main(){
    scanf("%lld%lld%lld", &n, &m, &k);
    if(k == -1 && ((n % 2) != (m % 2))){
        printf("0");
        return 0;
    }
    t = expow(expow(2, n - 1), m - 1);
    printf("%lld\n", t);
    return 0;
}
