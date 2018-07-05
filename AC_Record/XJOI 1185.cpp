//XJOI 1185
#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a, b, n, c;
    scanf("%lld", &n);
    if(n == 1){
        printf("0");
        return 0;
    }
    if(n == 2){
        printf("1");
        return 0;
    }
    a = 0;
    b = 1;
    for(int i = 3; i <= n; i++){
        c = a + b;
        a = b;
        b = c;
    }
    printf("%lld", b);
    return 0;
}