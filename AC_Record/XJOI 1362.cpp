//XJOI 1362
#include<bits/stdc++.h>
using namespace std;
long long a, b, k, c;
int l, s[110];
void pan(long long x){
    l = 0;
    while(x){
        l++;
        s[l] = x % 10;
        x /= 10;
    }
    while(l && k){
        k--;
        if(k == 0){
            printf("%d", s[l]);
            exit(0);
        }
        l--;
    }
    return;
}
int main(){
    scanf("%lld%lld%lld", &a, &b, &k);
    pan(a);
    pan(b);
    while(1){
        c = a + b;
        a = b;
        b = c;
        pan(b);
    }
    return 0;
}