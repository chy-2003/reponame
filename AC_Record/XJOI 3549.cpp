//XJOI 3549
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    if(n % 2 == 0) printf("-%d", n / 2); else printf("%d", n - n / 2);
    return 0;
}