//XJOI 3303
#include<bits/stdc++.h>
using namespace std;
long long n, k;
int main(){
    scanf("%lld%lld", &n, &k);
    for(int i = 1; i <= k; i++)
     if(n % 5 == 0) n /= 5;
    for(int i = 1; i <= k; i++)
     if(n % 2 == 0) n /= 2;
    printf("%lld", n);
    for(int i = 1; i <= k; i++) printf("0");
    return 0;
}