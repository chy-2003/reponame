//XJOI 3277
#include<bits/stdc++.h>
using namespace std;
int n, ans;
int main(){
    scanf("%d", &n);
    ans = -2147483647;
    int t = 0;
    int x;
    for(int i = 1; i <= n; i++){
        scanf("%d", &x);
        if(t < 0) t = 0;
        t += x;
        ans = max(ans, t);
    }
    printf("%d", ans);
    return 0;
}