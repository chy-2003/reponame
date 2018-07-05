//XJOI 1106
#include<bits/stdc++.h>
#define LL long long
using namespace std;
double n;
int main(){
    scanf("%lf", &n);
    printf("%d\n", (int)n);
    printf("%d\n", (n - (int)n) ? (int)n + 1 : int(n));
    return 0;
}