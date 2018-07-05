//XJOI 1112
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int main(){
    int x, y;
    scanf("%d%d", &x, &y);
    if(x < y) swap(x, y);
    printf("%d\n%d\n", x, y);
    return 0;
}