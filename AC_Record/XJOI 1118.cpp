//XJOI 1118
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    if(n == 1){
        printf("0");
        return 0;
    }
    if(n == 2){
        printf("0 1");
        return 0;
    }
    int x = 0, y = 1, t;
    printf("0 1 ");
    for(int i = 3; i <= n; i++){
        t = x + y;
        x = y;
        y = t;
        printf("%d ", t);
    }
    return 0;
}