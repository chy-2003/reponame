//XJOI 1138
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    int t = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            t++;
            printf("%4d", t);
        }
        printf("\n");
    }
    return 0;
}