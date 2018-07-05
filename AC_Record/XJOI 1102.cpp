//XJOI 1102
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n, m, k;
int main(){
    scanf("%d%d%d", &n, &m, &k);
    printf("%d\n%d\n", 2 * n * m + 2 * n *k + 2 * m * k, n * m * k);
    return 0;
}