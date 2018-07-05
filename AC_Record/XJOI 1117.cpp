//XJOI 1117
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    double ans = 100;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) ans *= 1.08;
    printf("%.2f", ans);
    return 0;
}