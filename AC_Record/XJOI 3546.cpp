//XJOI 3546
#include<bits/stdc++.h>
using namespace std;
int a, b, c, d;
int main(){
    scanf("%d%d%d%d", &a, &b, &c, &d);
    printf("%d", (c * 60 + d) - (a * 60 + b));
    return 0;
}