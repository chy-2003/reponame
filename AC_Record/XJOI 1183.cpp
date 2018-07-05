//XJOI 1183
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, a[2010];
    scanf("%ds", &n);
    if(n == 1){
        printf("1=1");
        return 0;
    }
    memset(a, 0, sizeof(a));
    for(int i = 2; i <= n; i++){
        if(a[i]) continue;
        for(int j = i * 2; j <= n; j += i)
         a[j] = 1;
    }
    printf("%d=", n);
    int b = 0, t;
    for(int i = 2; i <= n; i++){
        if(a[i]) continue;
        if(n % i != 0) continue;
        if(b) printf("*");
        printf("%d", i);
        t = 0;
        while(n % i == 0){
            t++;
            n /= i;
        }
        if(t > 1){
            printf("^%d", t);
        }
        b = 1;
    }
    return 0;
}