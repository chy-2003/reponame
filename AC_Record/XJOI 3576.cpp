//XJOI 3576
#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n - i; j++) printf("    ");
        for(int j = 1; j <= i; j++) printf(" O      ");
        printf("\n");
        for(int j = 1; j <= n - i; j++) printf("    ");
        for(int j = 1; j <= i; j++) printf("/|\\     ");
        printf("\n");
        for(int j = 1; j <= n - i; j++) printf("    ");
        for(int j = 1; j <= i; j++) printf("/ \\     ");
        printf("\n");
    }
    return 0;
}