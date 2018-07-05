//XJOI 3306
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int a1, a2, a3, b1, b2, b3;
int main(){
    while(scanf("%d%d", &a1, &b1) == 2){
        scanf("%d%d%d%d", &a2, &b2, &a3, &b3);
        if((a1 >= a2 + a3 && b1 >= max(b2, b3)) ||
           (a1 >= a2 + b3 && b1 >= max(b2, a3)) ||
           (a1 >= b2 + a3 && b1 >= max(a2, b3)) ||
           (a1 >= b2 + b3 && b1 >= max(a2, a3)) ||
           (b1 >= a2 + a3 && a1 >= max(b2, b3)) ||
           (b1 >= a2 + b3 && a1 >= max(b2, a3)) ||
           (b1 >= b2 + a3 && a1 >= max(a2, b3)) ||
           (b1 >= b2 + b3 && a1 >= max(a2, a3))) printf("YES\n"); else
        printf("NO\n");
    }
    return 0;
}