//XJOI 1175
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int main(){
    int x;
    scanf("%d", &x);
    if((x % 2 == 0) && (x != 2)) printf("YES, you can divide the watermelon into two even parts.");
    else printf("NO, you can't divide the watermelon into two even parts.");
    return 0;
}