#include<bits/stdc++.h>
using namespace std;
long long l, p[50010], b[50010];
long long n, m;
long long prime(long long x){
    if(x < 2) return 0;
    for(long long i = 1; p[i] * p[i] <= x; i++)
        if(x % p[i] == 0) return 0;
    return 1;
}
int main(){
    for(long long i = 2; i <= 50000; i++){
        if(b[i] == 1) continue;
        l++; p[l] = i;
        for(long long j = i + i; j <= 50000; j += i)
            b[j] = 1;
    }
    cin >> n >> m;
    for(long long i = n; i <= m; i++)
        if(prime(i)) printf("%lld ", i);
    return 0;
}