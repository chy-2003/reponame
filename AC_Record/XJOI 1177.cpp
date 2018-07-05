//XJOI 1177
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int main(){
    int n, m, x;
    scanf("%d%d%d", &n, &m, &x);
    int a, b;
    a = n / x;
    if(n % x) a++;
    b = m / x;
    if(m % x) b++;
    printf("%d", a * b);
    return 0;
}