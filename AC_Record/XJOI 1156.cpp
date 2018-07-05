//XJOI 1156
#include<bits/stdc++.h>
using namespace std;
int main(){
    double t, x, ans = 0;
    scanf("%lf", &x);
    t = x;
    int i = 1;
    while(abs(x / i) >= 1e-5){
        ans = ans + x / i;
        i++;
        x = x * t;
    }
    ans = ans + x / i;
    printf("%.6f", ans);
    return 0;
}