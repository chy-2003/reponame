//XJOI 1130
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, ans = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
     if(n % i == 0) ans += i;
    printf("%d\n", ans);
    return 0;
}