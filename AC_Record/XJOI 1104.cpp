//XJOI 1104
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n, m;
int main(){
    scanf("%d%d", &n, &m);
    printf("%d+%d=%d\n", n, m, n + m);
    printf("%7d\n", n);
    printf("+%6d\n", m);
    printf("-------\n");
    printf("%7d\n", n + m);
    return 0;
}