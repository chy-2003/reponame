//XJOI 3558
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(scanf("%d", &n) == 1){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n - i; j++) printf(" ");
            for(int j = 1; j <= i * 2 - 1; j++) printf("*");
            printf("\n");
        }
    }
    return 0;
}