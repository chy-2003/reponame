//XJOI 3550
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    int ans = 0;
    while(n != 1){
        ans++;
        if(n % 2 == 0) n /= 2; else n = n * 3 + 1;
    }
    printf("%d", ans);
    return 0;
}