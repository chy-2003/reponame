//XJOI 1190
#include<bits/stdc++.h>
using namespace std;
int gcd(int x, int y){
    int m = x % y;
    while(m){
        x = y;
        y = m;
        m = x % y;
    }
    return y;
}
int main(){
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", gcd(a, b));
    return 0;
}