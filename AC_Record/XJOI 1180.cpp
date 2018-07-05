//XJOI 1180
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int main(){
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    printf("%d", min(b + 1, n - a));
    return 0;
}