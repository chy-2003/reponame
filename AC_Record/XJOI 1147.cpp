//XJOI 1147
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    int ans = 0;
    while(n){
        ans += n % 10;
        n /= 10;
    }
    printf("%d", ans);
    return 0;
}