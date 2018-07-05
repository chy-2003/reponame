//XJOI 1198
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m, t, maxnum, ans = 0;
    scanf("%d%d", &n, &m);
    maxnum = -2147483647;
    for(int i = 1; i <= n; i++){
        scanf("%d", &t);
        maxnum = max(maxnum, t);
    }
    ans += maxnum;
    maxnum = -2147483647;
    for(int i = 1; i <= m; i++){
        scanf("%d", &t);
        maxnum = max(maxnum, t);
    }
    ans += maxnum;
    printf("%d\n", ans);
    return 0;
}