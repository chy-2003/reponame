//XJOI 1195
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, ans, x, y, minnum;
    while(scanf("%d", &n) == 1){
        ans = 0;
        minnum = 1000;
        for(int i = 1; i <= n; i++){
            scanf("%d%d", &x, &y);
            minnum = min(minnum, y);
            ans += x * minnum;
        }
        printf("%d\n", ans);
    }
    return 0;
}