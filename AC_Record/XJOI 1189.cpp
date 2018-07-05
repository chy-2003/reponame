//XJOI 1189
#include<bits/stdc++.h>
using namespace std;
int main(){
    int y, k, n;
    scanf("%d%d%d", &y, &k, &n);
    int t = k;
    int b = 0;
    while(t <= n){
        if(t >= y){
            printf("%d ", t - y);
            b = 1;
        }
        t += k;
    }
    if(!b) printf("-1");
    return 0;
}