//XJOI 3551
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    double ans = 0;
    int t = 0;
    for(int i = 1; i <= n; i++){
        if(i % 2 == 1) t += i * 2 - 1; else t -= i * 2 - 1;
        ans += (double)1 / t;
    }
    printf("%.3lf", ans);
     
    return 0;
}