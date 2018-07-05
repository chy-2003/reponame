//XJOI 1241
#include<bits/stdc++.h>
using namespace std;
long long n;
long long s(long long x){
    long long num = 0;
    while(x){
        num += x % 10;
        x /= 10;
    }
    return num;
}
int main(){
    cin >> n;
    for(long long x = (int)sqrt(n); x * x + 81 * x >= n; x--){
        if(x * x + x * s(x) == n){
            printf("%d", x);
            return 0;
        }
    }
    printf("-1");
    return 0;
}