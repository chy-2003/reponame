//XJOI 1111
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int main(){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf("The maximum number is : %d\n", max(a, max(c, b)));
    printf("The minimum number is : %d\n", min(a, min(b, c)));
    return 0;
}