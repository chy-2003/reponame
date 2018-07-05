//XJOI 1105
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n;
int main(){
    scanf("%d", &n);
    n *= n;
    printf("%d\n", (n % 1000 / 100) * 10 + (n % 100 / 10));
    return 0;
}