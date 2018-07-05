//XJOI 1116
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    double ans = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
     ans = ans + (double)1 / i;
    printf("%.6f", ans);
    return 0;
}