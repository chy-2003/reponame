//XJOI 3552
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, ans = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        ans += (i + 1) * i / 2;
    }
    printf("%d", ans);
    return 0;
}