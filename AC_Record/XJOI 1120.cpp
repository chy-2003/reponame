//XJOI 1120
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a, b, ans = 0;
    scanf("%d%d", &a, &b);
    int t, sum;
    for(int i = a; i <= b; i++){
        t = i;
        sum = 0;
        while(t){
            sum += t % 10;
            t /= 10;
        }
        if(sum % 5 == 0) ans++;
    }
    printf("%d\n", ans);
    return 0;
}