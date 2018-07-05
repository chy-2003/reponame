//XJOI 1210
#include<bits/stdc++.h>
using namespace std;
long long n, a[40], sum;
long long c(long long x, long long y){
    long long t;
    memset(a, 0, sizeof(a));
    for(long long i = x; i > x - y; i--){
        t = i;
        for(long long j = 2; j * j <= t; j++){
            while(t % j == 0){
                a[j]++;
                t /= j;
            }
        }
            if(t > 1) a[t]++;
    }
    for(long long i = 1; i <= y; i++){
        t = i;
        for(long long j = 2; j * j <= t; j++){
            while(t % j == 0){
                a[j]--;
                t /= j;
            }
        }
            if(t > 1) a[t]--;
    }
    long long cnt = 1;
    for(long long i = 2; i <= 30; i++){
        for(long long j = 1; j <= a[i]; j++) cnt *= i;
    }
    return cnt;
}
int main(){
    scanf("%d", &n);
    if(n == 1){
        printf("(a+b)^1 = a + b");
        return 0;
    }
    if(n == 0){
        printf("(a+b)^0 = 1");
        return 0;
    }
    printf("(a+b)^%d = ", n);
    printf("a^%d + ", n);
    for(long long i = 1; i < n; i++){
        printf("%d*", c(n, i));
        printf("a");
        if(n - i != 1) printf("^%d", n - i);
        printf("*");
        printf("b");
        if(i != 1) printf("^%d", i);
        printf(" + ");
    }
    printf("b^%d", n);
    return 0;
}