//XJOI 1003
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    int num;
    int b = 0;
    for(int i = 2; i * i <= n; i++){
        if(n % i != 0) continue;
        num = 0;
        while(n % i == 0){
            n /= i;
            num++;
        }
        if(b > 0) printf("*");
        b = 1;
        printf("%d", i);
        if(num > 1) printf("^%d", num);
    }
    if(n > 1){
        if(b > 0) printf("*");
        printf("%d", n);
    }
    return 0;
}